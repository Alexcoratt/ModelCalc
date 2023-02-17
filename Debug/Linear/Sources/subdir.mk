################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Linear/Sources/number.cpp \
../Linear/Sources/vector.cpp 

CPP_DEPS += \
./Linear/Sources/number.d \
./Linear/Sources/vector.d 

OBJS += \
./Linear/Sources/number.o \
./Linear/Sources/vector.o 


# Each subdirectory must supply rules for building sources it contributes
Linear/Sources/%.o: ../Linear/Sources/%.cpp Linear/Sources/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/run/media/alexsm/LinuxFiles/Workshop/EclipseWorkshop/ModelCalc/Linear/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Linear-2f-Sources

clean-Linear-2f-Sources:
	-$(RM) ./Linear/Sources/number.d ./Linear/Sources/number.o ./Linear/Sources/vector.d ./Linear/Sources/vector.o

.PHONY: clean-Linear-2f-Sources

