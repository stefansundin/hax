package main

import (
  "fmt"
  "encoding/hex"
)

func main() {
  input := "1c0111001f010100061a024b53535009181c"
  xor_s := "686974207468652062756c6c277320657965"
  bytes_input, _ := hex.DecodeString(input)
  bytes_xor_s, _ := hex.DecodeString(xor_s)
  bytes_xord := make([]byte, 0)
  for i := 0; i < len(bytes_input); i++ {
    bytes_xord = append(bytes_xord, bytes_input[i] ^ bytes_xor_s[i])
  }
  xord_str := hex.EncodeToString(bytes_xord)
  fmt.Println(xord_str)
}
