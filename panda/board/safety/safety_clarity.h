static int honda_clarity_fwd_hook(int bus_num, CAN_FIFOMailBox_TypeDef *to_fwd) {
    int addr = GET_ADDR(to_fwd);
    int bus_fwd = -1;
  if (bus_num == 0) {

    // send 0x221 to bus 2
    if (addr == 0x221 || (to_fwd->RIR>>21) == 0x221) {
      bus_fwd = 2;
      puts("0x221 DETECTED\n");
    }

    // send 0x255 to bus 2
    if (addr == 0x255 || (to_fwd->RIR>>21) == 0x255) {
      bus_fwd = 2;
      puts("0x255 DETECTED\n");
    }

    // send 0x296 to bus 2
    if (addr == 0x296 || (to_fwd->RIR>>21) == 0x296) {
      bus_fwd = 2;
      puts("0x296 DETECTED\n");
    }

    // send 0x37b to bus 2
    if (addr == 0x37B || (to_fwd->RIR>>21) == 0x37B) {
      bus_fwd = 2;
      puts("0x37B DETECTED\n");
    }
  }
  return bus_fwd;
}

const safety_hooks honda_clarity_hooks = {
  .init = nooutput_init,
  .rx = default_rx_hook,
  .tx = alloutput_tx_hook,
  .tx_lin = alloutput_tx_lin_hook,
  .fwd = honda_clarity_fwd_hook,
};
