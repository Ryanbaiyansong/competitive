for s in[*open(0)][2::2]:f=len(s)%2;print(2-(f^any(f^1&int(x)for x in s[f::2])))
