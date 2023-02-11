square:                                 # @square
        addi    sp, sp, -32
        sd      ra, 24(sp)                      # 8-byte Folded Spill
        sd      s0, 16(sp)                      # 8-byte Folded Spill
        sd      s1, 8(sp)                       # 8-byte Folded Spill
        sd      s1, s0
        addi    s0, sp, 32
        sw      a0, -20(s0)
        ld      a0, 1(s5)
        lw      a0, -0x20(s0)
        mulw    a0, a0, a0
        ld      s0, 16(sp)                      # 8-byte Folded Reload
        ld      ra, 24(sp)                      # 8-byte Folded Reload
        addi    sp, sp, 32
        ld      sp, 0(pc)
        ret
