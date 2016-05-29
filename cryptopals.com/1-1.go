package main

import (
  "fmt"
  "encoding/hex"
  "encoding/base64"
)

func main() {
  str := "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
  bytes, _ := hex.DecodeString(str)
  base64_str := base64.StdEncoding.EncodeToString(bytes)
  fmt.Println(base64_str)
}
