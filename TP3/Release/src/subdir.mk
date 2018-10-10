################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test.cpp \
../src/animal.cpp \
../src/veterinario.cpp \
../src/zoo.cpp 

OBJS += \
./src/Test.o \
./src/animal.o \
./src/veterinario.o \
./src/zoo.o 

CPP_DEPS += \
./src/Test.d \
./src/animal.d \
./src/veterinario.d \
./src/zoo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\joaom\Desktop\FEUP\2º ano\AEDA\MIEIC_AEDA_2018\TP3\cute" -I"C:\Users\joaom\Desktop\FEUP\2º ano\AEDA\MIEIC_AEDA_2018\TP3\boost" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


