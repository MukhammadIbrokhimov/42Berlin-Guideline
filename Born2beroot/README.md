# Born 2 Be Root

Welcome to the **Born 2 Be Root** project! This repository is dedicated to creating a fully secure virtual machine environment, combining cutting-edge technologies and robust security practices.


# Born2BeRoot Setup and Configuration Guide

Welcome to the Born2BeRoot project! This guide will help you download, install, and configure a secure virtual machine (VM) while introducing essential Linux administration concepts.

---

## Table of Contents

1. [Overview](#overview)
2. [Requirements](#requirements)
3. [Step-by-Step Setup](#step-by-step-setup)
   - [Downloading the Virtual Machine](#downloading-the-virtual-machine)
   - [Installing the Virtual Machine](#installing-the-virtual-machine)
   - [Configuring the Virtual Machine](#configuring-the-virtual-machine)
   - [Setting Up SSH and Firewall](#setting-up-ssh-and-firewall)
   - [Password Policies and User Management](#password-policies-and-user-management)
4. [Validation and Evaluation](#validation-and-evaluation)
5. [Frequently Used Commands](#frequently-used-commands)
6. [Conclusion](#conclusion)

---

## Overview

The Born2BeRoot project is a practical exercise in virtual machine setup and Linux system administration. By the end of this guide, you will have configured a VM with secure password policies, user groups, and SSH access. This is a foundational skill for developers, DevOps engineers, and system administrators.

---

## Requirements

- **Virtualization Software**: [VirtualBox](https://www.virtualbox.org/) or any other hypervisor.
- **Operating System ISO**: [Debian NetInstall ISO](https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/).
- **Basic Linux Knowledge**: Command-line familiarity is helpful but not mandatory.

---

## Step-by-Step Setup

### Downloading the Virtual Machine

1. Go to the [Debian ISO repository](https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/).
2. Download the latest `debian-xx.x.x-amd64-netinst.iso` file.

### Installing the Virtual Machine

1. Open VirtualBox and create a new VM:
   - **Machine Name**: Use a descriptive name (e.g., `Born2BeRoot`).
   - **Memory**: Allocate at least 1024 MB.
   - **Disk Size**: Set 12 GB or higher with dynamic allocation.
2. Attach the Debian ISO to the VM's optical drive under **Settings > Storage**.
3. Start the VM and follow the Debian installer prompts.

### Configuring the Virtual Machine

1. Select "Guided - use entire disk and set up encrypted LVM" for partitioning.
2. Set a hostname (e.g., `yourname42`) and a strong password.
3. Create a user (without `42` in the username) and assign a password.

### Part 4.1 - Installing Sudo

1. First type `su -` to login in as the root user.
2. Then type `apt-get update -y` 
3. Then type `apt-get upgrade -y` 
4. Then type `apt install sudo`
5. Then type `usermod -aG sudo your_username` to add user in the sudo group (To check if user is in sudo group, type `getent group sudo`)
6. Type `sudo visudo` to open sudoers file
7. Lastly find - # User privilege specification, type `your_username  	ALL=(ALL) ALL`

### Part 4.2 - Installing Git and Vim

1. Then type `apt-get install git -y` to install Git
2. Then type `git --version` to check the Git Version

### Part 4.3 - Installing and Configuring SSH (Secure Shell Host)

1. Type `sudo apt install openssh-server`
2. Type `sudo systemctl status ssh` to check SSH Server Status
3. Type `sudo vim /etc/ssh/sshd_config`
4. Find this line `#Port22` 
5. Change the line to `Port 4242` without the # (Hash) in front of it
6. Save and Exit Vim 
7. Then type `sudo grep Port /etc/ssh/sshd_config` to check if the port settings are right
8. Lastly type `sudo service ssh restart` to restart the SSH Service 

### Part 4.4 - Installing and Configuring UFW (Uncomplicated Firewall)

1. First type `apt-get install ufw` to install UFW
2. Type `sudo ufw enable` to inable UFW
3. Type `sudo ufw status numbered` to check the status of UFW
4. Type `sudo ufw allow ssh` to configure the Rules
5. Type `sudo ufw allow 4242` to configure the Port Rules
6. Lastly Type `sudo ufw status numbered` to check the status of UFW 4242 Port


## Part 5 Connecting to SSH

0. To exit your Virtual Machine and use your mouse, press `command` on your Apple Keyboard and your mouse should appear
1. Go to your Virtual Box Program
2. Click on your Virtual Machine and select `Settings`
3. Click `Network` then `Adapter 1` then `Advanced` and then click on `Port Forwarding`
![1*rCj_FeuZ5Rm2abz48qhulg](https://user-images.githubusercontent.com/58959408/174720900-39eda7e0-9be8-453c-94f1-4aa1a6b10951.png)
4. Change the Host Port to `4243` and Guest Port to `4242`
5. Then head back to your Virtual Machine
6. Type `sudo systemctl restart ssh` to restart your SSH Server
7. Type `sudo service sshd status` to check your SSH Status
8. Open an iTerm and type the following `ssh your_username@127.0.0.1 -p 4242`
9. In case an error occurs, then type `rm ~/.ssh/known_hosts` in your iTerm and then retype `ssh your_username@127.0.0.1 -p 4242`
10. Lastly type `exit` to quit your SSH iTerm Connection 


## Part 6 - Continue Configurating Your Virtual Machine

### Part 6.1 - Setting Password Policy

1. First type `sudo apt-get install libpam-pwquality` to install Password Quality Checking Library
2. Then type `sudo vim /etc/pam.d/common-password`

3. Find this line. `password		requisite		pam_deny.so` or
<img width="828" alt="Screen Shot 2022-07-29 at 6 40 34 PM" src="https://user-images.githubusercontent.com/58959408/181726262-8f8b7027-1929-4dda-8ac5-3957d3a1bd3a.png">
4. Add this to the end of that line `minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`

- 4.1 The line should now look like this - `password  requisite     pam_pwquality.so  retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`
<img width="800" alt="179329787-1b718843-9272-43e4-8d92-8d83933cc938" src="https://user-images.githubusercontent.com/58959408/181725921-c1e6c2b1-9dd3-46c5-b738-111467bdb394.png">

5. Save and Exit Vim
6. Next type in your Virtual Machine `sudo vim /etc/login.defs`
7. Find this part `PASS_MAX_DAYS 9999` `PASS_MIN_DAYS 0` `PASS_WARN_AGE 7`
8. Change that part to `PASS_MAX_DAYS 30` and `PASS_MIN_DAYS 2` keep `PASS_WARN_AGE 7` as the same
9. Lastly type `sudo reboot` to reboot the change affects

### Part 6.2 - Creating a Group

1. First type `sudo groupadd user42` to create a group
2. Then type `sudo groupadd evaluating` to create an evaluating group
3. Lastly type `getent group` to check if the group has been created

### Part 6.3 - Creating a User and Assigning Them Into The Group

1. First type `cut -d: -f1 /etc/passwd` to check all local users
2. Type `sudo adduser new_username` to create a username - write down your new_username, as you will need this later on. 
- 2.1 Type `sudo usermod -aG user42 your_username`
- 2.2 Type `sudo usermod -aG evaluating your_new_username`
3. Type `getent group user42` to check if the user is the group
4. Type `getent group evaluating` to check the group
5. Type `groups` to see which groups the user account belongs to
6. Lastly type `chage -l your_new_username` to check if the password rules are working in users

### Part 6.4 - Creating sudo.log

1. First type `cd ~/../../`
4. Then type `cd var/log`
5. Then type `mkdir sudo` (if it already exists, then continue to the next step).
6. Then type `cd sudo && touch sudo.log`
7. Then type `cd ~/../`

### Part 6.4.1 - Configuring Sudoers Group

1. First type `sudo nano /etc/sudoers` to go the sudoers file
2. Now edit your sudoers file to look like the following by adding in all of the defaults in the image below - ![1*N4Ad-9k0vfvnWKNC5q6MjQ](https://user-images.githubusercontent.com/58959408/174725518-0ebf1dac-4126-4869-9ba0-b1d05ce313c9.png)

```
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/bin:/sbin:/bin"
Defaults	badpass_message="Password is wrong, please try again!"
Defaults	passwd_tries=3
Defaults	logfile="/var/log/sudo/sudo.log"
Defaults	log_input, log_output
Defaults	requiretty
```

### Part 6.5 - Crontab Configuation

1. Then type `apt-get install -y net-tools` to install the netstat tools
2. Then type `cd /usr/local/bin/`
3. Then type `touch monitoring.sh`
4. Lastly type `chmod 777 monitoring.sh`

### Part 6.5.1 - Copy Text Below onto Virtual Machine 

1. Copy this text (To copy the text below, hover with your mouse to the right corner of the text below and a copy icon will appear). 
```
#!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) 
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -Ht state established | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
```
2. Then open up a iTerm2 seperate from your Virtual Machine and type in iTerm `ssh your_host_name42@127.0.0.1 -p 4243` and then type your password, when it asks for it. 
3. Then type `cd /usr/local/bin`.
4. Then type `nano monitoring.sh` and paste the text above into the vim monitoring.sh you just created, by doing `command` + `v` on your Apple keyboard.
5. Save and Exit your `monitoring.sh`
- 5.1 - Then type `exit` to exit the iTerm SSH Login.
- 5.2 - Then go back to your Virtual Machine (not iTerm) and continue on with the steps below. 
6. Then type `sudo visudo` to open your sudoers file 
7. Add in this line `your_username ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh` under where its written %sudo ALL=(ALL:ALL) ALL
8. It should look like this
![1*l-7LtAqCon1gRkV3dY3qiQ](https://user-images.githubusercontent.com/58959408/174727595-11dbb2f9-9c34-4d11-870b-f832ea4a9224.png)
9. Then exit and save your sudoers file
10. Now type `sudo reboot` in your Virtual Machine to reboot sudo
11. Type `sudo /usr/local/bin/monitoring.sh` to execute your script as su (super user)
12. Type `sudo crontab -u root -e` to open the crontab and add the rule
13. Lastly at the end of the crontab, type the following `*/10 * * * * /usr/local/bin/monitoring.sh` this means that every 10 mins, this script will show


## Part 7 - Signature.txt (Last Part Before Defence)

⚠️ Warning: before you generate a signature number, turn off your Virtual Machine. ⚠️

1. Open iTerm and type `cd`
1. Then type `cd sgoinfre/students/<your_intra_username>/VirtualBox VMs`
2. Type `shasum VirtualBox.vdi` or whatever your Virtual Machine is called (This can take from a few seconds to 5 mins).
3. Copy the output number and create a signature.txt file and paste that number in the file. 
3. Now you submit the signature.txt file with the output number in it.

### 🥳 CONGRATULATIONS! YOU HAVE NOW FINISHED!
