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