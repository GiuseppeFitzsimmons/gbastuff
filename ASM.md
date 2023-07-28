### `lsl r6, r0, 0x00`

Left shift r0 onto r6, at offset 0
=> `r6 = r0;`

### `lsl r3, r2, 0x02`

Left shift r2 onto r3, at offset 2
=> `r3 = r2 << 2;`
=> `r3 = r2 * 2;`

### `08000390 e7fe b $08000390`

At address 08000390, branch to address 08000390
=> while(1)

### `ldr r0, [r0, r0]`
=> ldr destination_register, [base_register, offset_register/index_register]

The LDR pseudo-instruction loads a register with either:
* a 32-bit constant value
* an address.

In this case, we load the address of r0, plus the value inside r0 as the offset, and the 32-bit value stored at r0 + r0 is stored inside r0.
=> `r0 = *(uint32_t*)(r0 + r0);`

Looks familiar? It should: `#define REG_DISPCNT *((volatile u32 *)(MEM_IO + 0x0000))`