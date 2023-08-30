
## kata 01

#### Description
Create two functions to encode and then decode a string using the Rail Fence Cipher. This cipher is used to encode a string by placing each character successively in a diagonal along a set of "rails". First start off moving diagonally and down. When you reach the bottom, reverse direction and move diagonally and up until you reach the top rail. Continue until you reach the end of the string. Each "rail" is then read left to right to derive the encoded string.

#### Example
Input:
```
W       E       E
  E   R   H   R
    A       E
```

Output:
```
WERERHRAE
```

#### DOC
[Rail fence cipher | Wikipedia](https://en.wikipedia.org/wiki/Rail_fence_cipher)
