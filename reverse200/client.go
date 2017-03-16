package main

import "fmt"
import "bufio"
import "net"
import "crypto/sha1"
import "strings"

//g@m30fpwn-rs
const KEY_LENGTH = 12
const KEY1 string = "2d74a51890f323ffcf93f6c40e9d25526005646f"
const KEY2 string = "0088a59b167fd84f9b8942928a32ed5e63c06b2b"
const KEY3 string = "3d5c669aace49abf10bf7add76911765b86768e5"


func main() {

  con, _ := net.Dial("tcp", "1.2.3.4:8090")

  if con != nil {
    for {
      check := false

      msg, _ := bufio.NewReader(con).ReadString('\n')
      msg = strings.TrimSpace(msg)

      if len(msg) == KEY_LENGTH {
        part1 := []byte(msg[0:4])
        part1_key := fmt.Sprintf("%x", sha1.Sum(part1))
        //fmt.Printf("%s\n", part1_key)

        if part1_key == KEY1 {
          part2 := []byte(msg[4:8])
          part2_key := fmt.Sprintf("%x", sha1.Sum(part2))
          //fmt.Printf("%s\n", part2_key)

          if part2_key == KEY2 {
            part3 := []byte(msg[8:12])
            part3_key := fmt.Sprintf("%x", sha1.Sum(part3))
            //fmt.Printf("%s\n", part3_key)

            if part3_key == KEY3 {
              check = true
            }
          }
        }
      }

      if check {
        fmt.Fprintf(con, "Yes master!\n")
        fmt.Fprintf(con, "Your flag is: GoP_{%s}", msg)
      } else {
        fmt.Fprintf(con, "You are not my master!\n")
      }

      //fmt.Printf(msg)
    }
  } else {
    fmt.Printf("Somebody call 911 :P\n")
  }
}
