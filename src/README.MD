## Source Code

Here is where you will find the source code for the project<br>


## C Code
C code has been compiled with `TCC: Tiny C Compiler` at http://bellard.org/tcc/

-  `UUID_Fix.c` Fixes VMWare Bios UUID and MAC Address to Randomize the VM. This runs before your virtual machine is turned on. 
-  `Volid_Name.c` Generates random volume id (serial number) for your hard drive. It needs `volumeid.exe` and it runs inside your running virtual machine.
  

## Extra Files
- `FixDisk.reg` Fixes registry entry to remove VMware drive type. You'll need to run this inside your running virtual machine.
