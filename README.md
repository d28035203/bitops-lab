# Register Rodeo

Bit-level drills in C: set, clear, toggle, test, and popcount on 32-bit words, plus pretty binary printing.

## Build

```bash
make
./bitops demo
./bitops show 0xF0
./bitops set 0 3
./bitops toggle 8 3
./bitops popcount 255
```

Bits are numbered 0..31 (0 = LSB).

## License

MIT
