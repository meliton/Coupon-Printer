# Coupon-Printer

## The Coupon Challenge

I came across some coupon printing software that does not play nice with your computer. Specifically, it does not uninstall cleanly. The fix for this is to install this in a virtual machine. Guess what... it doesn't install in a VM... or does it... hence, The Coupon Challenge.

First step. Get yourself good quality virtual machine software with non-persistent drives and printing capabilities.
- VMware Player. Get the latest version from your favorite software source.

Once you install VMware, you'll need to enable virtual printer support.
- Open VMWare Player
- `Player | File | Preferences ...`
- Enable the option `Enable Virtual Printers` 

Next, you'll need an operating system supported by the coupon printing software. You can grab a low-memory VM from a legal source like `IE8 on Win7` and run that in `VMware`...
- The <a href="http://modern.ie" target="_blank">modern.ie website</a> has a whole supply of them. 

Once you install your OS in VMware, you'll need to add the following file and directory to your OS to allow VM installation <br>
-  `C:\vmok\vmok.txt` and the file can be empty

Now, you'll need to shutdown your virtual machine and make some configuration changes to the `.vmx` file of your virtual machine. The `.vmx` file typically can be found at `Computer | My Documents | Virtual Machines` folder. Use a text editor to make changes to the file.<br>

Your hard drive can be set up to remember (persistent) or forget changes (non-persistent)<br>
We want the VM to forget, so we will add the non-persistent line at the bottom of the `.vmx` file.<br>

NOTE: You use only ONE of these lines and add it in your .vmx config<br>

For IDE drives<br>
    `ide0:0.mode = "independent-nonpersistent" ` <br>
For SCSI drives<br>
    `scsi0:0.mode = "independent-nonpersistent" ` <br>
	
Now, you can restart your virtual machine. 

Also, note that after every reboot, you'll need to change the registry entry to rename the VMWare drive that the operating system detects. The coupon printer will look for `VMWare Drive` in the registry and stops the printer from installing.
To get around this pesky little road block, open `regedit` and navigate to `HKLM\SYSTEM\CurrentControlSet\Services\Disk\Enum`

Change it to something like `Disk_IDE_Hard_Drive`..... <br>
- Use `FixDisk.reg` from the `src` folder to do this automatically for you.


