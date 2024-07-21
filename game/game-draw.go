package game

import rl "github.com/gen2brain/raylib-go/raylib"
import "OlafRPG/debug"

func (g *Game) Draw() {
	rl.BeginDrawing()
	rl.ClearBackground(rl.Black)

	player.Draw()
	
	if debug.Debug { // Draw FPS in the top left
		rl.DrawFPS(0, 0)
	}
	rl.EndDrawing()
}
