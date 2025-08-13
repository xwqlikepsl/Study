/*
 * @Descripttion: 
 * @version: 
 * @Author: smile
 * @Date: 2025-03-09 22:05:28
 * @LastEditors: smile
 * @LastEditTime: 2025-03-27 15:45:37
 */
__asm void PendSV_Handler(void) {
	//blockPtr = &block;
	IMPORT blockPtr 	
	LDR R0,=blockPtr 
	LDR R0,[R0]			  
	LDR R0,[R0]     
	
	//寄存器入栈 STMDB批量往内存地址里面写寄存器
	//! 表示在存储完成后更新 R0 的值
	STMDB R0!,{R4-R11}
	
	//更新栈指针
	LDR R1,=blockPtr
	LDR R1,[R1]
	STR R0,[R1]     
	
	//杂项操作
	ADD R4,R4,#1
	ADD R5,R5,#1
	
	//出栈
	LDMIA R0!,{R4-R11}
	
	BX LR
	
	
}