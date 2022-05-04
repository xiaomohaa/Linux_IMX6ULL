# 编译器
CROSS_COMPILE 	?= arm-linux-gnueabihf-
# 项目名称
TARGET		  	?= led

# 编译器相关
CC 				:= $(CROSS_COMPILE)gcc
LD				:= $(CROSS_COMPILE)ld
OBJCOPY 		:= $(CROSS_COMPILE)objcopy
OBJDUMP 		:= $(CROSS_COMPILE)objdump

# 头文件路径
INCDIRS 		:= imx6ul \
				   core/inc \
# 源文件路径   			   
SRCDIRS			:= project \
				   core/src
# 通过函数patsubst给变量 INCDIRS添加一个“-I”
# 因为Makefile语法要求指明头文件目录的时候需要加上“-I”。
# makefile引用变量的语法为：$(变量名)				   
INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))

# 使用函数foreach和wildcard挑选出所有.s汇编文件
SFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
# 使用函数foreach和wildcard挑选出所有.c文件
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

# 使用notdir函数去掉.c和.s文件的路径
SFILENDIR		:= $(notdir  $(SFILES))
CFILENDIR		:= $(notdir  $(CFILES))

# OBJ文件路径
SOBJS			:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
OBJS			:= $(SOBJS) $(COBJS)

# 指定编译时搜索.s和.c文件的路径
VPATH			:= $(SRCDIRS)

# 指定一个伪目标clean
.PHONY: clean
	

$(TARGET).bin : $(OBJS)
	$(LD) -Timx6ul.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS) : obj/%.o : %.S
	$(CC) -Wall -nostdlib -c -O2  $(INCLUDE) -o $@ $<

$(COBJS) : obj/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2  $(INCLUDE) -o $@ $<

clean:
	rm -rf $(TARGET).elf $(TARGET).dis $(TARGET).bin $(COBJS) $(SOBJS)

	
