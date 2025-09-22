int reverseBits(int n) {
    uint32_t _n = n;
    _n = ((_n & 0xffff0000) >> 16) | ((_n & 0x0000ffff) << 16);
    _n = ((_n & 0xff00ff00) >>  8) | ((_n & 0x00ff00ff) <<  8);
    _n = ((_n & 0xf0f0f0f0) >>  4) | ((_n & 0x0f0f0f0f) <<  4);
    _n = ((_n & 0xcccccccc) >>  2) | ((_n & 0x33333333) <<  2);
    _n = ((_n & 0xaaaaaaaa) >>  1) | ((_n & 0x55555555) <<  1);
    return _n;
}