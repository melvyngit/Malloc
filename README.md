# PROJET MALLOC ETNA


### Project introduction :

The main goal of the project is to reprogram the malloc / free system functions which allow to allocate and free memory dynamically. The use of the brk and sbrk functions allow us to modify the size of the data segment.
<br />

### Strategy implemented :

The strategy adopted is the "first data segment" method, also called "first fit". This solution is easy to implement, however, it does not fight against fragmentation and does not provide the best possible performance. This method remains reliable nevertheless.
<br />

### Summary of the method :

1) Walk through the blocks
2) Make sure that the block contains enough data
3) Make sure that the block is not already allocated
4) Allocate according to the size requested by the user
