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
SOURCEFILES_QUOTED_IF_SPACED=Main.c Motion.c UARTSetup.c Physics.c EncoderSetup.c InterruptSetup.c OscSetup.c PortsSetup.c PWMSetup.c Startup.c AccelTable.c VelocityTest.c BinaryPrinters.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Main.o ${OBJECTDIR}/Motion.o ${OBJECTDIR}/UARTSetup.o ${OBJECTDIR}/Physics.o ${OBJECTDIR}/EncoderSetup.o ${OBJECTDIR}/InterruptSetup.o ${OBJECTDIR}/OscSetup.o ${OBJECTDIR}/PortsSetup.o ${OBJECTDIR}/PWMSetup.o ${OBJECTDIR}/Startup.o ${OBJECTDIR}/AccelTable.o ${OBJECTDIR}/VelocityTest.o ${OBJECTDIR}/BinaryPrinters.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Main.o.d ${OBJECTDIR}/Motion.o.d ${OBJECTDIR}/UARTSetup.o.d ${OBJECTDIR}/Physics.o.d ${OBJECTDIR}/EncoderSetup.o.d ${OBJECTDIR}/InterruptSetup.o.d ${OBJECTDIR}/OscSetup.o.d ${OBJECTDIR}/PortsSetup.o.d ${OBJECTDIR}/PWMSetup.o.d ${OBJECTDIR}/Startup.o.d ${OBJECTDIR}/AccelTable.o.d ${OBJECTDIR}/VelocityTest.o.d ${OBJECTDIR}/BinaryPrinters.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Main.o ${OBJECTDIR}/Motion.o ${OBJECTDIR}/UARTSetup.o ${OBJECTDIR}/Physics.o ${OBJECTDIR}/EncoderSetup.o ${OBJECTDIR}/InterruptSetup.o ${OBJECTDIR}/OscSetup.o ${OBJECTDIR}/PortsSetup.o ${OBJECTDIR}/PWMSetup.o ${OBJECTDIR}/Startup.o ${OBJECTDIR}/AccelTable.o ${OBJECTDIR}/VelocityTest.o ${OBJECTDIR}/BinaryPrinters.o

# Source Files
SOURCEFILES=Main.c Motion.c UARTSetup.c Physics.c EncoderSetup.c InterruptSetup.c OscSetup.c PortsSetup.c PWMSetup.c Startup.c AccelTable.c VelocityTest.c BinaryPrinters.c


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
	${MP_CC} $(MP_EXTRA_CC_PRE)  Main.c  -o ${OBJECTDIR}/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Motion.o: Motion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Motion.o.d 
	@${RM} ${OBJECTDIR}/Motion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Motion.c  -o ${OBJECTDIR}/Motion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Motion.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Motion.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/UARTSetup.o: UARTSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/UARTSetup.o.d 
	@${RM} ${OBJECTDIR}/UARTSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UARTSetup.c  -o ${OBJECTDIR}/UARTSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UARTSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/UARTSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Physics.o: Physics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Physics.o.d 
	@${RM} ${OBJECTDIR}/Physics.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Physics.c  -o ${OBJECTDIR}/Physics.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Physics.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Physics.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/EncoderSetup.o: EncoderSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/EncoderSetup.o.d 
	@${RM} ${OBJECTDIR}/EncoderSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EncoderSetup.c  -o ${OBJECTDIR}/EncoderSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EncoderSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/EncoderSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/InterruptSetup.o: InterruptSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/InterruptSetup.o.d 
	@${RM} ${OBJECTDIR}/InterruptSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  InterruptSetup.c  -o ${OBJECTDIR}/InterruptSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/InterruptSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/InterruptSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/OscSetup.o: OscSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/OscSetup.o.d 
	@${RM} ${OBJECTDIR}/OscSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OscSetup.c  -o ${OBJECTDIR}/OscSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/OscSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/OscSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PortsSetup.o: PortsSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PortsSetup.o.d 
	@${RM} ${OBJECTDIR}/PortsSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PortsSetup.c  -o ${OBJECTDIR}/PortsSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PortsSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PortsSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PWMSetup.o: PWMSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PWMSetup.o.d 
	@${RM} ${OBJECTDIR}/PWMSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PWMSetup.c  -o ${OBJECTDIR}/PWMSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PWMSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PWMSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Startup.o: Startup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Startup.o.d 
	@${RM} ${OBJECTDIR}/Startup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Startup.c  -o ${OBJECTDIR}/Startup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Startup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Startup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/AccelTable.o: AccelTable.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AccelTable.o.d 
	@${RM} ${OBJECTDIR}/AccelTable.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AccelTable.c  -o ${OBJECTDIR}/AccelTable.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/AccelTable.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/AccelTable.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/VelocityTest.o: VelocityTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/VelocityTest.o.d 
	@${RM} ${OBJECTDIR}/VelocityTest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  VelocityTest.c  -o ${OBJECTDIR}/VelocityTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/VelocityTest.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/VelocityTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/BinaryPrinters.o: BinaryPrinters.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BinaryPrinters.o.d 
	@${RM} ${OBJECTDIR}/BinaryPrinters.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BinaryPrinters.c  -o ${OBJECTDIR}/BinaryPrinters.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/BinaryPrinters.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/BinaryPrinters.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Main.c  -o ${OBJECTDIR}/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Motion.o: Motion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Motion.o.d 
	@${RM} ${OBJECTDIR}/Motion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Motion.c  -o ${OBJECTDIR}/Motion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Motion.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Motion.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/UARTSetup.o: UARTSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/UARTSetup.o.d 
	@${RM} ${OBJECTDIR}/UARTSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UARTSetup.c  -o ${OBJECTDIR}/UARTSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UARTSetup.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/UARTSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Physics.o: Physics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Physics.o.d 
	@${RM} ${OBJECTDIR}/Physics.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Physics.c  -o ${OBJECTDIR}/Physics.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Physics.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Physics.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/EncoderSetup.o: EncoderSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/EncoderSetup.o.d 
	@${RM} ${OBJECTDIR}/EncoderSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EncoderSetup.c  -o ${OBJECTDIR}/EncoderSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EncoderSetup.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/EncoderSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/InterruptSetup.o: InterruptSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/InterruptSetup.o.d 
	@${RM} ${OBJECTDIR}/InterruptSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  InterruptSetup.c  -o ${OBJECTDIR}/InterruptSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/InterruptSetup.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/InterruptSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/OscSetup.o: OscSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/OscSetup.o.d 
	@${RM} ${OBJECTDIR}/OscSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OscSetup.c  -o ${OBJECTDIR}/OscSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/OscSetup.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/OscSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PortsSetup.o: PortsSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PortsSetup.o.d 
	@${RM} ${OBJECTDIR}/PortsSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PortsSetup.c  -o ${OBJECTDIR}/PortsSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PortsSetup.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PortsSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PWMSetup.o: PWMSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PWMSetup.o.d 
	@${RM} ${OBJECTDIR}/PWMSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PWMSetup.c  -o ${OBJECTDIR}/PWMSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PWMSetup.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/PWMSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Startup.o: Startup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Startup.o.d 
	@${RM} ${OBJECTDIR}/Startup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Startup.c  -o ${OBJECTDIR}/Startup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Startup.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/Startup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/AccelTable.o: AccelTable.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AccelTable.o.d 
	@${RM} ${OBJECTDIR}/AccelTable.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AccelTable.c  -o ${OBJECTDIR}/AccelTable.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/AccelTable.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/AccelTable.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/VelocityTest.o: VelocityTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/VelocityTest.o.d 
	@${RM} ${OBJECTDIR}/VelocityTest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  VelocityTest.c  -o ${OBJECTDIR}/VelocityTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/VelocityTest.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/VelocityTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/BinaryPrinters.o: BinaryPrinters.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BinaryPrinters.o.d 
	@${RM} ${OBJECTDIR}/BinaryPrinters.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BinaryPrinters.c  -o ${OBJECTDIR}/BinaryPrinters.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/BinaryPrinters.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off -std=gnu99
	@${FIXDEPS} "${OBJECTDIR}/BinaryPrinters.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../Program\ Files/Microchip/xc16/v1.11/lib/dsPIC33E/libp33EP512MU814-elf.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "..\..\..\..\Program Files\Microchip\xc16\v1.11\lib\dsPIC33E\libp33EP512MU814-elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../Program\ Files/Microchip/xc16/v1.11/lib/dsPIC33E/libp33EP512MU814-elf.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ServoBrainV0_1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "..\..\..\..\Program Files\Microchip\xc16\v1.11\lib\dsPIC33E\libp33EP512MU814-elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
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
