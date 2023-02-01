square:                                 # @square
        addi    sp, sp, -32
        sd      ra, 24(sp)                      # 8-byte Folded Spill
        sd      s0, 16(sp)                      # 8-byte Folded Spill
        addi    s0, sp, 32
        sw      a0, -20(s0)
        lw      a0, -20(s0)
        mulw    a0, a0, a0
        ld      s0, 16(sp)                      # 8-byte Folded Reload
        ld      ra, 24(sp)                      # 8-byte Folded Reload
        addi    sp, sp, 32
        ret
