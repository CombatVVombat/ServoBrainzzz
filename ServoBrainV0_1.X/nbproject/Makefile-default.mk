#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Main.c Motion.c UARTSetup.c Physics.c EncoderSetup.c InterruptSetup.c OscSetup.c PortsSetup.c PWMSetup.c Startup.c AccelTable.c BinaryPrinters.c VelocityHold.c PushButton.c MotionDebug.c PositionHold.c abs.c D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/HomeSwitch.c D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T1Interrupt.c D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T2Interrupt.c D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/ProgramState.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Main.o ${OBJECTDIR}/Motion.o ${OBJECTDIR}/UARTSetup.o ${OBJECTDIR}/Physics.o ${OBJECTDIR}/EncoderSetup.o ${OBJECTDIR}/InterruptSetup.o ${OBJECTDIR}/OscSetup.o ${OBJECTDIR}/PortsSetup.o ${OBJECTDIR}/PWMSetup.o ${OBJECTDIR}/Startup.o ${OBJECTDIR}/AccelTable.o ${OBJECTDIR}/BinaryPrinters.o ${OBJECTDIR}/VelocityHold.o ${OBJECTDIR}/PushButton.o ${OBJECTDIR}/MotionDebug.o ${OBJECTDIR}/PositionHold.o ${OBJECTDIR}/abs.o ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o ${OBJECTDIR}/_ext/2094536564/ProgramState.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Main.o.d ${OBJECTDIR}/Motion.o.d ${OBJECTDIR}/UARTSetup.o.d ${OBJECTDIR}/Physics.o.d ${OBJECTDIR}/EncoderSetup.o.d ${OBJECTDIR}/InterruptSetup.o.d ${OBJECTDIR}/OscSetup.o.d ${OBJECTDIR}/PortsSetup.o.d ${OBJECTDIR}/PWMSetup.o.d ${OBJECTDIR}/Startup.o.d ${OBJECTDIR}/AccelTable.o.d ${OBJECTDIR}/BinaryPrinters.o.d ${OBJECTDIR}/VelocityHold.o.d ${OBJECTDIR}/PushButton.o.d ${OBJECTDIR}/MotionDebug.o.d ${OBJECTDIR}/PositionHold.o.d ${OBJECTDIR}/abs.o.d ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o.d ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o.d ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o.d ${OBJECTDIR}/_ext/2094536564/ProgramState.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Main.o ${OBJECTDIR}/Motion.o ${OBJECTDIR}/UARTSetup.o ${OBJECTDIR}/Physics.o ${OBJECTDIR}/EncoderSetup.o ${OBJECTDIR}/InterruptSetup.o ${OBJECTDIR}/OscSetup.o ${OBJECTDIR}/PortsSetup.o ${OBJECTDIR}/PWMSetup.o ${OBJECTDIR}/Startup.o ${OBJECTDIR}/AccelTable.o ${OBJECTDIR}/BinaryPrinters.o ${OBJECTDIR}/VelocityHold.o ${OBJECTDIR}/PushButton.o ${OBJECTDIR}/MotionDebug.o ${OBJECTDIR}/PositionHold.o ${OBJECTDIR}/abs.o ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o ${OBJECTDIR}/_ext/2094536564/ProgramState.o

# Source Files
SOURCEFILES=Main.c Motion.c UARTSetup.c Physics.c EncoderSetup.c InterruptSetup.c OscSetup.c PortsSetup.c PWMSetup.c Startup.c AccelTable.c BinaryPrinters.c VelocityHold.c PushButton.c MotionDebug.c PositionHold.c abs.c D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/HomeSwitch.c D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T1Interrupt.c D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T2Interrupt.c D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/ProgramState.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512MU814
MP_LINKER_FILE_OPTION=,--script=p33EP512MU814.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Main.c  -o ${OBJECTDIR}/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Motion.o: Motion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Motion.o.d 
	@${RM} ${OBJECTDIR}/Motion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Motion.c  -o ${OBJECTDIR}/Motion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Motion.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Motion.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/UARTSetup.o: UARTSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/UARTSetup.o.d 
	@${RM} ${OBJECTDIR}/UARTSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UARTSetup.c  -o ${OBJECTDIR}/UARTSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UARTSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/UARTSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Physics.o: Physics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Physics.o.d 
	@${RM} ${OBJECTDIR}/Physics.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Physics.c  -o ${OBJECTDIR}/Physics.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Physics.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Physics.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/EncoderSetup.o: EncoderSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/EncoderSetup.o.d 
	@${RM} ${OBJECTDIR}/EncoderSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EncoderSetup.c  -o ${OBJECTDIR}/EncoderSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EncoderSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/EncoderSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/InterruptSetup.o: InterruptSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/InterruptSetup.o.d 
	@${RM} ${OBJECTDIR}/InterruptSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  InterruptSetup.c  -o ${OBJECTDIR}/InterruptSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/InterruptSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/InterruptSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/OscSetup.o: OscSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/OscSetup.o.d 
	@${RM} ${OBJECTDIR}/OscSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OscSetup.c  -o ${OBJECTDIR}/OscSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/OscSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/OscSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PortsSetup.o: PortsSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PortsSetup.o.d 
	@${RM} ${OBJECTDIR}/PortsSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PortsSetup.c  -o ${OBJECTDIR}/PortsSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PortsSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PortsSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PWMSetup.o: PWMSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PWMSetup.o.d 
	@${RM} ${OBJECTDIR}/PWMSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PWMSetup.c  -o ${OBJECTDIR}/PWMSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PWMSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PWMSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Startup.o: Startup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Startup.o.d 
	@${RM} ${OBJECTDIR}/Startup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Startup.c  -o ${OBJECTDIR}/Startup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Startup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Startup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/AccelTable.o: AccelTable.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AccelTable.o.d 
	@${RM} ${OBJECTDIR}/AccelTable.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AccelTable.c  -o ${OBJECTDIR}/AccelTable.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/AccelTable.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/AccelTable.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/BinaryPrinters.o: BinaryPrinters.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BinaryPrinters.o.d 
	@${RM} ${OBJECTDIR}/BinaryPrinters.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BinaryPrinters.c  -o ${OBJECTDIR}/BinaryPrinters.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/BinaryPrinters.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/BinaryPrinters.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/VelocityHold.o: VelocityHold.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/VelocityHold.o.d 
	@${RM} ${OBJECTDIR}/VelocityHold.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  VelocityHold.c  -o ${OBJECTDIR}/VelocityHold.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/VelocityHold.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/VelocityHold.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PushButton.o: PushButton.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PushButton.o.d 
	@${RM} ${OBJECTDIR}/PushButton.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PushButton.c  -o ${OBJECTDIR}/PushButton.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PushButton.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PushButton.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MotionDebug.o: MotionDebug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/MotionDebug.o.d 
	@${RM} ${OBJECTDIR}/MotionDebug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MotionDebug.c  -o ${OBJECTDIR}/MotionDebug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MotionDebug.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/MotionDebug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PositionHold.o: PositionHold.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PositionHold.o.d 
	@${RM} ${OBJECTDIR}/PositionHold.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PositionHold.c  -o ${OBJECTDIR}/PositionHold.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PositionHold.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PositionHold.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/abs.o: abs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/abs.o.d 
	@${RM} ${OBJECTDIR}/abs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  abs.c  -o ${OBJECTDIR}/abs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/abs.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/abs.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2094536564/HomeSwitch.o: D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/HomeSwitch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2094536564 
	@${RM} ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o.d 
	@${RM} ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/HomeSwitch.c  -o ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2094536564/HomeSwitch.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/_ext/2094536564/HomeSwitch.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2094536564/T1Interrupt.o: D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T1Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2094536564 
	@${RM} ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T1Interrupt.c  -o ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2094536564/T1Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/_ext/2094536564/T1Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2094536564/T2Interrupt.o: D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T2Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2094536564 
	@${RM} ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T2Interrupt.c  -o ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2094536564/T2Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/_ext/2094536564/T2Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2094536564/ProgramState.o: D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/ProgramState.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2094536564 
	@${RM} ${OBJECTDIR}/_ext/2094536564/ProgramState.o.d 
	@${RM} ${OBJECTDIR}/_ext/2094536564/ProgramState.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/ProgramState.c  -o ${OBJECTDIR}/_ext/2094536564/ProgramState.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2094536564/ProgramState.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/_ext/2094536564/ProgramState.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Main.c  -o ${OBJECTDIR}/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Motion.o: Motion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Motion.o.d 
	@${RM} ${OBJECTDIR}/Motion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Motion.c  -o ${OBJECTDIR}/Motion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Motion.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Motion.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/UARTSetup.o: UARTSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/UARTSetup.o.d 
	@${RM} ${OBJECTDIR}/UARTSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UARTSetup.c  -o ${OBJECTDIR}/UARTSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UARTSetup.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/UARTSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Physics.o: Physics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Physics.o.d 
	@${RM} ${OBJECTDIR}/Physics.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Physics.c  -o ${OBJECTDIR}/Physics.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Physics.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Physics.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/EncoderSetup.o: EncoderSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/EncoderSetup.o.d 
	@${RM} ${OBJECTDIR}/EncoderSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EncoderSetup.c  -o ${OBJECTDIR}/EncoderSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EncoderSetup.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/EncoderSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/InterruptSetup.o: InterruptSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/InterruptSetup.o.d 
	@${RM} ${OBJECTDIR}/InterruptSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  InterruptSetup.c  -o ${OBJECTDIR}/InterruptSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/InterruptSetup.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/InterruptSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/OscSetup.o: OscSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/OscSetup.o.d 
	@${RM} ${OBJECTDIR}/OscSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OscSetup.c  -o ${OBJECTDIR}/OscSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/OscSetup.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/OscSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PortsSetup.o: PortsSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PortsSetup.o.d 
	@${RM} ${OBJECTDIR}/PortsSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PortsSetup.c  -o ${OBJECTDIR}/PortsSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PortsSetup.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PortsSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PWMSetup.o: PWMSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PWMSetup.o.d 
	@${RM} ${OBJECTDIR}/PWMSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PWMSetup.c  -o ${OBJECTDIR}/PWMSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PWMSetup.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PWMSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Startup.o: Startup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Startup.o.d 
	@${RM} ${OBJECTDIR}/Startup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Startup.c  -o ${OBJECTDIR}/Startup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Startup.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Startup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/AccelTable.o: AccelTable.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AccelTable.o.d 
	@${RM} ${OBJECTDIR}/AccelTable.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AccelTable.c  -o ${OBJECTDIR}/AccelTable.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/AccelTable.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/AccelTable.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/BinaryPrinters.o: BinaryPrinters.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BinaryPrinters.o.d 
	@${RM} ${OBJECTDIR}/BinaryPrinters.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BinaryPrinters.c  -o ${OBJECTDIR}/BinaryPrinters.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/BinaryPrinters.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/BinaryPrinters.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/VelocityHold.o: VelocityHold.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/VelocityHold.o.d 
	@${RM} ${OBJECTDIR}/VelocityHold.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  VelocityHold.c  -o ${OBJECTDIR}/VelocityHold.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/VelocityHold.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/VelocityHold.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PushButton.o: PushButton.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PushButton.o.d 
	@${RM} ${OBJECTDIR}/PushButton.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PushButton.c  -o ${OBJECTDIR}/PushButton.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PushButton.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PushButton.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MotionDebug.o: MotionDebug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/MotionDebug.o.d 
	@${RM} ${OBJECTDIR}/MotionDebug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MotionDebug.c  -o ${OBJECTDIR}/MotionDebug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MotionDebug.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/MotionDebug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PositionHold.o: PositionHold.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PositionHold.o.d 
	@${RM} ${OBJECTDIR}/PositionHold.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PositionHold.c  -o ${OBJECTDIR}/PositionHold.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PositionHold.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PositionHold.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/abs.o: abs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/abs.o.d 
	@${RM} ${OBJECTDIR}/abs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  abs.c  -o ${OBJECTDIR}/abs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/abs.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/abs.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2094536564/HomeSwitch.o: D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/HomeSwitch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2094536564 
	@${RM} ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o.d 
	@${RM} ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/HomeSwitch.c  -o ${OBJECTDIR}/_ext/2094536564/HomeSwitch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2094536564/HomeSwitch.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/_ext/2094536564/HomeSwitch.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2094536564/T1Interrupt.o: D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T1Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2094536564 
	@${RM} ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T1Interrupt.c  -o ${OBJECTDIR}/_ext/2094536564/T1Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2094536564/T1Interrupt.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/_ext/2094536564/T1Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2094536564/T2Interrupt.o: D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T2Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2094536564 
	@${RM} ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/T2Interrupt.c  -o ${OBJECTDIR}/_ext/2094536564/T2Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2094536564/T2Interrupt.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/_ext/2094536564/T2Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2094536564/ProgramState.o: D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/ProgramState.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2094536564 
	@${RM} ${OBJECTDIR}/_ext/2094536564/ProgramState.o.d 
	@${RM} ${OBJECTDIR}/_ext/2094536564/ProgramState.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  D:/Programming/LocalGit/ServoBrainzzz/ServoBrainV0_1.X/ProgramState.c  -o ${OBJECTDIR}/_ext/2094536564/ProgramState.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2094536564/ProgramState.o.d"      -mno-eds-warn  -g -omf=elf -O1 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/_ext/2094536564/ProgramState.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
