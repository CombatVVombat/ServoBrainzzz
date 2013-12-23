/**********************************************************************
* © 2008 Microchip Technology Inc.
*
* FileName:        main.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC33Fxxxx
* Compiler:        MPLAB® C30 v3.02 or higher
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and 
* intellectual property rights in the code accompanying this message and in all 
* derivatives hereto.  You may use this code, and any derivatives created by 
* any person or entity by or on your behalf, exclusively with Microchip's
* proprietary products.  Your acceptance and/or use of this code constitutes 
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S 
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER 
* IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), 
* STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, 
* PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF 
* ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN 
* ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT 
* ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO 
* THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO 
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify, test, 
* certify, or support the code.
*
* ADDITIONAL NOTES:
* Code Tested on:
* Explorer 16 board using the GP710 PIM and UART 2               
**********************************************************************/
#include "p33FJ256GP710.h"
#include "RTDM.h"

/*********************************************/
/********* Configuration Bits ****************/
/*********************************************/
/* Internal FRC Oscillator */
_FOSCSEL(FNOSC_FRC);

/*  Clock Switching is enabled and 
**  Fail Safe Clock Monitor is disabled
**	OSC2 Pin Function: OSC2 is Clock Output 
**	Primary Oscillator Mode: Disabled */
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON  & POSCMD_NONE); 

/*Watchdog Timer Enabled/disabled by user software*/
_FWDT(FWDTEN_OFF);  

/* Background Debug Enable Bit: Device will Reset in user mode
** Debugger/Emulator Enable Bit: Reset in operational mode
** JTAG Enable Bit: JTAG is disabled
** ICD communication channel select bits: communicate on PGC1/EMUC1 and PGD1/EMUD1 **/
_FICD(JTAGEN_OFF & ICS_PGD2);

/***********************  SYSTEM DEFINITIONS ******************************/
#define FCY  39615000          			 //Instruction Cycle Frequency
#define AMOUNT_OF_DATA_TO_BE_PLOTTED 256 //number of sanpshot samples expressed in 16-bit words since the Buffer is 16bit wide

///////////////////////////////////////////////////////////////////
/*************************** MAIN ********************************/
///////////////////////////////////////////////////////////////////
unsigned int MyVariable, Frequency, Amplitude;								//Varaible to be recored and its paramters to be modified using the DMCI sliders
unsigned int SnapShotBufferPlottedInDMCI[AMOUNT_OF_DATA_TO_BE_PLOTTED];		//buffer where the data is recorded
unsigned int * PointerToSnapShotBuffer = &SnapShotBufferPlottedInDMCI[0];	//Tail pointer required to plot circular buffers in DMCI
unsigned int * PointerToSnapShotBufferUpperLimit = &SnapShotBufferPlottedInDMCI[0] + AMOUNT_OF_DATA_TO_BE_PLOTTED -1;
																			//Buffer Upper limit

struct {
			unsigned TrigggerSnapshot: 	1;	//Tirgger variable to start recording the values of MyVariable
			unsigned LED_D3: 	1;			//Definition of Exp 16 LED D3-D6
			unsigned LED_D4: 	1;
			unsigned LED_D5: 	1;
			unsigned LED_D6: 	1;
			unsigned unused :		11;     
		}	MyFlags;

		
int main(void)
{

	// Configure Oscillator to operate the device at 40Mhz
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
	// Fosc= 7.37*43/(2*2)=79.23MHz

	PLLFBD=41;					// M=43
	CLKDIVbits.PLLPOST=0;		// N1=2
	CLKDIVbits.PLLPRE=0;		// N2=2
	OSCTUN=0;					// Tune FRC oscillator, if FRC is used

    // Disable Watch Dog Timer
	RCONbits.SWDTEN=0;

    // Clock switch to incorporate PLL
	__builtin_write_OSCCONH(0x01);		// Initiate Clock Switch to
										// FRC with PLL (NOSC=0b001)
	__builtin_write_OSCCONL(0x01);		// Start clock switching
	while (OSCCONbits.COSC != 0b001);	// Wait for Clock switch to occur

    // Wait for PLL to lock
	while(OSCCONbits.LOCK!=1) {};

	LATA = 0x0000;			//LED initial state is OFF
	TRISA = 0xFFF0;			// Config LED's 
	
	MyFlags.TrigggerSnapshot = 0;	//Snapshot trigger intial state is OFF
	Frequency = 1000;				//Initial Frequency of MyVariable saw-tooth wave
	Amplitude = 65535;				//Initial Amplitude of MyVariable saw-tooth wave
									// NOTE: DMCI is configured to auto-adjust the plot min and max values,
									//To notice amplitude changes on the DMCI plot, right click on the DMCI plot
									// goto to Extended Functions Menu > Customization > Axis, set the desired 
									//min an max values for the Y AXIS
									
	
	RTDM_Start();	//RTDM start function
					// Overview: 
					// Here is where the RTDM code initilizes the UART to be used to
					// exchange data wiht the host PC
					// Note:	
					// Some processors may have 2 UART modules, that is why it is required to
					// specify wich UART module is going to be used by RTDM	

	for(;;){
	
	LATAbits.LATA0 = MyFlags.LED_D3;	//Passing data from the boolean variables controlled
	LATAbits.LATA1 = MyFlags.LED_D4;	// in DMCI to the PORT A data registers
	LATAbits.LATA2 = MyFlags.LED_D5;	
	LATAbits.LATA3 = MyFlags.LED_D6;
	
	RTDM_ProcessMsgs();	// Overview: 
						// Here is where the RTDM code process the message received and then 
						// executes the required task. These tasks are reading an specified memory
						// location, writing an specified memory location, receive a communication
						// link sanity check command, or being asked for the size of the bufffers.
						
	MyVariable += Frequency;	//Here is were the variable is updated by the Application SW
	
	if(MyVariable > Amplitude)	//IF condition to check the max value of my variable
		MyVariable = 0;			// This section controls the max amplitude
	
	
	//If the TriggerSnapShot is ON then the values of the variable are recorded on the SnapShot Buffer,
	// if the TriggerSnapShot is OFF the values are not recorded  this is a lock condition in order to prevent that the
	// data recorded on the snapshot buffer are being updated while the target device is sending/receiving information 
	//to DMCI. If the data is  corrupted while a TX is in progress, DMCI will flush the received data and it 
	//will display an error message. The values won't be displayed on the graph	
	if(MyFlags.TrigggerSnapshot){	
		*PointerToSnapShotBuffer++ = MyVariable;							//Recordinf values
		if(PointerToSnapShotBuffer > PointerToSnapShotBufferUpperLimit){	//SnapShot Buffer is a circular buffer
			PointerToSnapShotBuffer = SnapShotBufferPlottedInDMCI;			
			MyFlags.TrigggerSnapshot = 0;	//Turning OFF the snapshot mode indicating that new data is available to be sent
											//DMCI user has to push the RECEIVE button in order to retrive data from the target
											//device
			}
		}
		
	}/*END OF THE INFINITE LOOP FOR*/

	RTDM_Close();	// Overview: 
					// Here is where the RTDM code closes the UART used to
					// exchange data wiht the host PC
	return 0;

}




