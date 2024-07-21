package game

import rl "github.com/gen2brain/raylib-go/raylib"

func (p *Player) Draw() {
	rl.DrawRectangleRec(p.bounds, rl.White)
}