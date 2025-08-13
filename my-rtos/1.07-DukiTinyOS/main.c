/*
 * @Descripttion: 
 * @version: 
 * @Author: smile
 * @Date: 2025-03-09 22:05:28
 * @LastEditors: smile
 * @LastEditTime: 2025-03-09 22:21:35
 */
#define NVIC_INT_CTRL   0xE000ED04
#define NVIC_PENDSVSET  0x10000000
#define NVIC_SYSORI2    0xE000ED22
#define NVIC_PENDSV_PRI 0x000000FF

#define MEM32(addr)     *(volatile unsigned long*)(addr)
#define MEM8(addr)     *(volatile unsigned char*)(addr)

void triggerPendSVC(void) {
	MEM8(NVIC_SYSORI2) = NVIC_PENDSV_PRI;//
	MEM32(NVIC_INT_CTRL) = NVIC_PENDSVSET;//触发PendSV异常	
}

typedef struct BlockType_t {
	unsigned long * stackPtr;
}BlockType_t;

BlockType_t *blockPtr;

void Delay(int time) {
	while(--time > 0);
}

int flag;
unsigned long stackBuffer[1024];
BlockType_t block;
int main() {
    block.stackPtr = &stackBuffer[1024];
	blockPtr = &block;
	
	for(;;) {
		flag = 0;
		Delay(200);
		flag = 1;
		Delay(200);
		triggerPendSVC();
	}
	return 0;
}