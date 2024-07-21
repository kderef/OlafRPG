package main

import (
	"OlafRPG/game"
)


// Run the Game //

func main() {
	game := game.New()

	game.SetHighDPI(false)
	game.SetResizable(true)

	game.Init(800, 450, "Hello, World!")
	defer game.Close()

	for !game.ShouldClose {
		game.Update()
		game.Draw()
	}
}