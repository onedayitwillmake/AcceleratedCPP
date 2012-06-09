################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AcceleratedCPP_9_1.cpp 

CC_SRCS += \
../src/Student_info.cc \
../src/grade.cc \
../src/median.cc 

OBJS += \
./src/AcceleratedCPP_9_1.o \
./src/Student_info.o \
./src/grade.o \
./src/median.o 

CC_DEPS += \
./src/Student_info.d \
./src/grade.d \
./src/median.d 

CPP_DEPS += \
./src/AcceleratedCPP_9_1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


