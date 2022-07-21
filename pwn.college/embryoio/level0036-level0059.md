
# [#] level 36

`/challenge/embryoio_level36 | cat stdout.txt -`

***
<br> <br><br>

# [#] level 37

`/challenge/embryoio_level37 | grep -E ^pwn`

***
<br> <br><br>

# [#] level 38

`/challenge/embryoio_level38 | sed -n '/pwn/p'`

***
<br> <br><br>

# [#] level 39

`/challenge/embryoio_level39 | rev | rev`

***
<br> <br><br>

# [#] level 40

`cat | /challenge/embryoio_level40`

***
<br> <br><br>

# [#] level 41

`rev | /challenge/embryoio_level41`

then reverse the given string and put in the input 

then exit by `ctrl+d`

***
<br> <br><br>

# [#] level 42

`vim my_script.sh`

```bash
/challenge/embryoio_level42 --noprofile
```

`bash my_script.sh | cat`

***
<br> <br><br>

# [#] level 43

`vim my_script.sh`

```bash
/challenge/embryoio_level43 --noprofile
```

`bash my_script.sh | grep -E ^pwn`

***
<br> <br><br>

# [#] level 44

`vim my_script.sh`

```bash
/challenge/embryoio_level44 --noprofile
```

`bash my_script.sh | sed -n '/pwn/p'`

***
<br> <br><br>

# [#] level 45

`vim my_script.sh`

```bash
/challenge/embryoio_level45 --noprofile
```

`bash my_script.sh | rev | rev`

***
<br> <br><br>

# [#] level 46

`vim my_script.sh`

```bash
/challenge/embryoio_level46 --noprofile
```

`cat | bash my_script.sh`

***
<br> <br><br>

# [#] level 47

`vim my_script.sh`

```bash
/challenge/embryoio_level47 --noprofile
```

`rev | rev | bash my_script.sh`


***
<br> <br><br>

# [#] level 48
`vim ipython.py`

```python
import subprocess
subprocess.run(["/challenge/embryoio_level48"])
python [ipython.py](<http://ipython.py/>) | cat
```

`vim my_script.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level48"])
```
`ipython | cat`

`In [1]: run fromLevel48.py`

this gives the flag

***
<br> <br><br>

# [#] level 49
`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level49"])
```

`python [ipython.py](<http://ipython.py/>) | grep -E ^pwn`  gives the flag

***
<br> <br><br>

# [#] level 50
`vim ipython.py`

```python
import subprocess
subprocess.run(["/challenge/embryoio_level50"])
```

`python [ipython.py](<http://ipython.py/>) | sed -n '/pwn/p'` gives the flag

***
<br> <br><br>

# [#] level 51

`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level51"])
```

`python [ipython.py](<http://ipython.py/>) | rev | rev` gives the flag

***
<br> <br><br>

# [#] level 52

`vim ipython.py`

```python
import subprocess
subprocess.run(["/challenge/embryoio_level52"])
```

`cat | python ipython.py` gives the flag

***
<br> <br><br>

# [#] level 53

`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level53"])
```

`rev | rev | python ipython.py` gives the flag

***
<br> <br><br>

# [#] level 54

`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level54"])
```

`python [ipython.py](<http://ipython.py/>) | cat` gives the flag

***
<br> <br><br>

# [#] level 55

`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level55"])
```

`python [ipython.py](<http://ipython.py/>) | grep -E ^pwn` gives the flag

***
<br> <br><br>

# [#] level 56

`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level56"])
```

`python [ipython.py](<http://ipython.py/>) | sed -n '/pwn.college/p'` gives the flag

***
<br> <br><br>

# [#] level 57

`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level57"])
python [ipython.py](<http://ipython.py/>) | cat
```

***
<br> <br><br>

# [#] level 58

`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level58"])
```

`cat | python [ipython.py](<http://ipython.py/>)` gives flag

***
<br> <br><br>

# [#] level 59

`vim ipython.py`
```python
import subprocess
subprocess.run(["/challenge/embryoio_level59"])
```

`rev | rev | python [ipython.py](<http://ipython.py/>)` gives the flag
