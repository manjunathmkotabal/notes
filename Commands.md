# Enable vt-x for ubuntu machine on a windows host 
- locate the VBoxManage.exe in your vertual box folder then execute the following 
```
VBoxManage modifyvm "vm_name" --nested-hw-virt on
```
- restart vbox
