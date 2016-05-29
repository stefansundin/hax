package main

import (
  "fmt"
  "encoding/hex"
)

func main() {
  input := "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
  freq := "ETAOINSHRDLUCMWFGYPBVKJXQZ"
  freq_array := []byte(freq)
  bytes_input, _ := hex.DecodeString(input)
  for _,d := range freq_array {
    output := make([]byte, 0)
    for _,c := range bytes_input {
      output = append(output, c ^ d)
    }
    fmt.Printf("%c: %s\n", d, string(output))
  }
}
