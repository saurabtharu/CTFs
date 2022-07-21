# [#] level 5

redirecting a file to the process’ `stdin`

```bash
./bin_file < /path/to/file/<file-name>
```



***





# [#] level 6

redirecting from a process’  `stdout`

```
./bin_file > /path/to/file/<file-name>
```



***



# [#] level 7

` env -i /challenge/embryoio_level7`  gives the flag

launching  program with 0 environment variables

```
env -i
		-i, --ignore-environment
              start with an empty environment

env -i /challenge/embryoio_level7
		runs the binary file with 0 environment variable
```



***



# [#] level 8

run the challenge program with bash script

```
hacker@embryoio_level8:~$ vim my_script.sh
#!/bin/bash
/challenge/embryoio_level8
```



***



# [#] level 9

run the binary `embryoio_level9` by `my_script.sh` and enter the specified password



***



# [#] level 10

run the binary `embryoio_level9` by `my_script.sh`

```
hacker@embryoio_level10:~$ vim my_script.sh
#!/bin/bash

/challenge/embryoio_level10 iudjtfhhma
```



***



# [#] level 11

run the binary `embryoio_level9` by `my_script.sh`after setting the environment variable `hbptjr=zvniasvgjy`



***



# [#] level 12

run the binary `embryoio_level9` by `my_script.sh`

```
$ cat my_script.sh
/challenge/embryoio_level12 < /tmp/hkadtg
$ cat > /tmp/hkadtg
hsnudpuf
```



***



# [#] level 13

create a file `/tmp/gblzuy`

```
vim my_script.sh
/challenge/embryoio_level13 > /tmp/gblzuy
```

`cat /tmp/gblzuy` we get the flag



***



# [#] level 14

run the binary `embryoio_level9` by `my_script.sh`

```
hacker@embryoio_level14:~$ cat my_script.sh
env -i /challenge/embryoio_level14
			# env -i runs the command with zero environment variable
```



***



# [#] level 15

```
vim script.py
from subprocess import call
call("/challenge/embryoio_level15")
```

then run the script using `ipython`

```
$ ipython
In [1]: run script.py
```



***



# [#] level 16

```
vim script.py
from subprocess import call
call("/challenge/embryoio_level16")
```

then run the script using `ipython`

```
$ ipython
In [1]: run script.py
```



***



# [#] level 17

```
vim script.py
from subprocess import call
call(["/challenge/embryoio_level17","nbzmenerpj"])
```

then run the script using `ipython`

```
$ ipython
In [1]: run script.py
```



***



# [#] level 18

set environment variable using `$ export xhsiux=vmeogvcpcj`

```
vim script.py
from subprocess import call
call("/challenge/embryoio_level18")
```

then run the script using `ipython`

```
$ ipython
In [1]: run script.py
```



***



# [#] level 19

```python
$ cat > /tmp/pwbllv
uzonsptl
vim script.py
import subprocess
with open('/tmp/pwbllv','r') as f:
	subprocess.run(["/challenge/embryoio_level19"],stdin=f)
```



***



# [#] level 20

```
vim script.py
import subprocess
open('/tmp/diwfff','w') as f:
     subprocess.run(["/challenge/embryoio_level20"],stdout=f)
cat /tmp/diwfff
[INFO] This challenge will now perform a bunch of checks.
[INFO] If you pass these checks, you will receive the flag.
[TEST] Performing checks on the parent process of this process.
[TEST] We will now check that that the process is an interactive ipython instance.
....
....
....
....
....
[GOOD] The file at the other end of my stdout looks okay!
[GOOD] Success! You have satisfied all execution requirements. Here is your flag:
pwn.college{soZM1WP6NAF5egAyzpvfLTFOFxP.dBjMsczNwQzW}
```



***



# [#] level 21

```
vim script.py
from subprocess import run
run(['env','-i','/challenge/embryoio_level21'])
```



***



# [#] level 22

```
vim my_script.py
from subprocess import run
run(['/challenge/embryoio_level22'])
```



***



# [#] level 23

```
vim my_script.py
from subprocess import run
run(['/challenge/embryoio_level23'])
```

then enter the password specified



***



# [#] level 24

```
vim my_script.py
from subprocess import run
run(['/challenge/embryoio_level24','kcspqbcpva'])
```



***



# [#] level 25

```
vim my_script.py
import os
from subprocess import run
os.environ['uclahj'] = 'hibrrridtw'
run(['/challenge/embryoio_level25'])
```



***



# [#] level 26

```
$ echo "prqmxvig" > /tmp/mishwo
vim my_script.py
from subprocess import run
with open('/tmp/mishwo','r') as f:
    run(["/challenge/embryoio_level26"],stdin=f)
```



***



# [#] level 27

```
vim my_script.py
from subprocess import run
with open('/tmp/tqlzyz','w') as f:
    run(["/challenge/embryoio_level27"],stdout=f)
```

then do `$ cat /tmp/tqlzyz`



***



# [#] level 28

```
vim my_script.py
from subprocess import run
run(['env','-i','/challenge/embryoio_level28'])
```