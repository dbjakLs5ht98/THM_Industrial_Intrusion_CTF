
undefined8 main(void)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  size_t sVar4;
  FILE *__stream;
  long in_FS_OFFSET;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158 [8];
  char local_118 [264];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_160 = 0xefcdab8967452301;
  printf("[?] Enter unlock code: ");
  pcVar2 = fgets((char *)local_158,0x40,stdin);
  if (pcVar2 == (char *)0x0) {
    fwrite("Error reading input\n",1,0x14,stderr);
    uVar3 = 1;
  }
  else {
    sVar4 = strcspn((char *)local_158,"\r\n");
    *(undefined *)((long)local_158 + sVar4) = 0;
    sVar4 = strnlen((char *)local_158,0x40);
    if (sVar4 == 8) {
      local_168 = local_158[0];
      transform(&local_168,8);
      iVar1 = memcmp(&local_168,&local_160,8);
      if (iVar1 == 0) {
        __stream = fopen("flag.txt","r");
        if (__stream == (FILE *)0x0) {
          perror("fopen");
          uVar3 = 1;
        }
        else {
          pcVar2 = fgets(local_118,0x100,__stream);
          if (pcVar2 == (char *)0x0) {
            fwrite("Error reading flag\n",1,0x13,stderr);
          }
          else {
            printf("[+] Access Granted! Flag: %s",local_118);
          }
          fclose(__stream);
          uVar3 = 0;
        }
      }
      else {
        puts("[!] Access Denied!");
        uVar3 = 1;
      }
    }
    else {
      puts("[!] Access Denied!");
      uVar3 = 1;
    }
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}
