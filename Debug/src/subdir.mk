################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ModelCalc.cpp 

CPP_DEPS += \
./src/ModelCalc.d 

OBJS += \
./src/ModelCalc.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/run/media/alexsm/LinuxFiles/Workshop/EclipseWorkshop/ModelCalc/Linear/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ModelCalc.d ./src/ModelCalc.o

.PHONY: clean-src

