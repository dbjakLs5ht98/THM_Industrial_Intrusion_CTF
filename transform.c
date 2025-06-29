
void transform(long param_1,ulong param_2)

{
  ulong local_10;
  
  local_10 = 0;
  while (local_10 < param_2) {
    *(byte *)(local_10 + param_1) = *(byte *)(local_10 + param_1) ^ 0x55;
    local_10 = local_10 + 1;
  }
  return;
}

