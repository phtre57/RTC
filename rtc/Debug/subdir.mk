################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ContratException.cpp \
../arret.cpp \
../auxiliaires.cpp \
../coordonnees.cpp \
../ligne.cpp \
../main.cpp \
../station.cpp \
../util.cpp \
../voyage.cpp 

OBJS += \
./ContratException.o \
./arret.o \
./auxiliaires.o \
./coordonnees.o \
./ligne.o \
./main.o \
./station.o \
./util.o \
./voyage.o 

CPP_DEPS += \
./ContratException.d \
./arret.d \
./auxiliaires.d \
./coordonnees.d \
./ligne.d \
./main.d \
./station.d \
./util.d \
./voyage.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

coordonnees.o: ../coordonnees.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"coordonnees.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


