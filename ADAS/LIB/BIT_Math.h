#ifndef _H_BIT_OPERATIONS
#define _H_BIT_OPERATIONS
#define clear_bit(reg,n) reg&=~(1<<n)
#define set_bit(reg,n) reg|=(1<<n)
#define toggle_bit(reg,n) reg^=(1<<n)
#define read_bit(reg,n) ( (reg & (1<<n))) >>n
#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)

#define WRITE_BIT(REG , BIT, VAL)    CLR_BIT(REG,BIT) | (val << BIT)
#endif
