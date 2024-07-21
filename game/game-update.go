package game

import rl "github.com/gen2brain/raylib-go/raylib"

func (g *Game) Update() {
	g.ShouldClose = g.ShouldClose || rl.WindowShouldClose()

	player.Update()
}