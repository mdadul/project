package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var mx, cnt int
var note []string

func add(splitted []string) {
	ll := len(splitted)
	cnt++
	note[cnt] = strings.Join(splitted[1:ll], " ")
	fmt.Println("[OK] The note was successfully created")

}
func list() {
	for i := 1; i <= cnt; i++ {
		fmt.Printf("[Info] %d: %s\n", i, note[i])
	}
}
func check(splitted []string) bool {
	c := 0
	for i := 2; i < len(splitted); i++ {
		if splitted[i] == "" {
			c++
		}
	}
	if c == len(splitted)-2 {
		return false
	} else {
		return true
	}

}
func update(splitted []string) {
	updateIdx := splitted[1]
	isInt := false
	for i := 0; i < len(updateIdx); i++ {
		if updateIdx[i] >= '0' && updateIdx[i] <= '9' {
			isInt = true
		}
	}
	if isInt {
		index, _ := strconv.Atoi(splitted[1])
		updtxt := strings.Join(splitted[2:], " ")

		if len(splitted) >= 3 && isValidNote2(splitted) == 1 && check(splitted) == true {
			if index > 0 && index <= mx {
				note[index] = updtxt
				fmt.Printf("[OK] The note at position %d was successfully updated\n", index)
			} else {
				fmt.Printf("[Error] Position %d is out of the boundary [1, %d]\n", index, mx)
			}
		} else {
			fmt.Println("[Error] Missing note argument")
		}
	} else {
		fmt.Printf("[Error] Invalid position: %s\n", updateIdx)
	}

}
func deleteElement(slice []string, index int) []string {
	return append(slice[:index], slice[index+1:]...)
}
func deleteNote(splitted []string) {
	deleteIdx := splitted[1]
	isInt := false
	for i := 0; i < len(deleteIdx); i++ {
		if deleteIdx[i] >= '0' && deleteIdx[i] <= '9' {
			isInt = true
		}
	}
	if isInt {
		index, _ := strconv.Atoi(splitted[1])
		if index > 0 && index <= mx {
			note = deleteElement(note, index)
			cnt = cnt - 1
			fmt.Printf("[OK] The note at position %d was successfully deleted\n", index)
		} else {
			fmt.Printf("[Error] Position %d is out of the boundaries [1, %d]n", index, mx)
		}
	} else {
		fmt.Printf("[Error] Invalid position: %s\n", deleteIdx)
	}

}
func isValidNote2(splitted []string) int {
	var idx int
	idx = len(splitted)

	if idx >= 2 {
		if splitted[1] == "" {
			return 0
		} else {
			return 1
		}
	} else if idx >= 3 {
		if splitted[2] == "" {
			return 0
		} else {
			return 1
		}
	}
	return 1
}
func main() {

	fmt.Println("Enter the maximum number of notes:")
	fmt.Scanf("%d", &mx)

	cnt = 0
	note = make([]string, mx+10, mx+10)

	fmt.Println("Enter a command and data: >")

	scanner := bufio.NewScanner(os.Stdin)

	for scanner.Scan() {
		line := scanner.Text()
		splitted := strings.Split(line, " ")

		switch splitted[0] {
		case "create":
			if cnt < mx {
				if isValidNote2(splitted) == 1 && len(splitted) > 1 {
					add(splitted)
				} else {
					fmt.Println("[Error] Missing note argument")
				}
			} else {
				fmt.Println("[Error] Notepad is full")
			}
		case "list":
			if cnt == 0 {
				fmt.Println("[Info] Notepad is empty")
			} else {
				list()
			}
		case "clear":
			cnt = 0
			fmt.Println("[OK] All notes were successfully deleted")
		case "update":
			if len(splitted) == 1 || isValidNote2(splitted) == 0 {
				fmt.Println("[Error] Missing position argument")
			} else if len(splitted) >= 2 && isValidNote2(splitted) == 0 {
				fmt.Println("[Error] Missing note argument")
			} else if cnt == 0 {
				fmt.Println("[Error] There is nothing to update")
			} else {
				update(splitted)
			}
		case "delete":
			if len(splitted) == 1 || isValidNote2(splitted) == 0 {
				fmt.Println("[Error] Missing position argument")
			} else if cnt == 0 {
				fmt.Println("[Error] There is nothing to delete")
			} else {
				deleteNote(splitted)
			}

		case "exit":
			fmt.Println("[Info] Bye!")
			return
		default:
			fmt.Println("[Error] Unknown command")
		}
		fmt.Println("Enter a command and data: >")
	}

}
