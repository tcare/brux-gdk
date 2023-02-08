#include "api/sprites.hpp"

#include "brux/main.hpp"

#include "brux/global.hpp"
#include "brux/sprite.hpp"

namespace BruxAPI {

/////////////
// SPRITES //
/////////////

std::string spriteName(int sprite) {
	if(vcSprites.size() <= sprite || sprite < 0 || vcSprites[sprite] == 0)
		return "N/A";

	return vcSprites[sprite]->name;
}

int findSprite(const std::string& name) {
	//Print(0, "Searching for sprite: %s", name);
	//xyPrint(0, "Number of sprites to search: %i", vcSprites.size());

	for (size_t i = 0; i < vcSprites.size(); i++) {
		if (vcSprites[i] != 0) {
			//xyPrint(0, "Current sprite name: %s", vcSprites[i]->getname());
			if (vcSprites[i]->getname() == name) {
				return vcSprites[i]->getnum();
			}
		}
	}

	return 0;
}

int newSprite(const std::string& i, int w, int h, int m, int p, int px, int py) {
	xySprite* newsprite = new xySprite(i, w, h, m, p, px, py);
	return newsprite->getnum();
}

int newSpriteFT(int t, int w, int h, int m, int p, int px, int py) {
	xySprite* newsprite = new xySprite(t, w, h, m, p, px, py);
	return newsprite->getnum();
}

/** Macros to help easily check if a sprite is valid. **/
#define SPRITE_CHECK_VALID       if (vcSprites.size() <= i || vcSprites[i] == 0)
#define SPRITE_CHECK_VALID_VOID  SPRITE_CHECK_VALID return
#define SPRITE_CHECK_VALID_INT   SPRITE_CHECK_VALID return 0

void drawSprite(int i, float f, float x, float y) {
	SPRITE_CHECK_VALID_VOID;
	vcSprites[i]->draw(f, x, y);
}

void drawSpriteEx(int i, float f, float x, float y, float a, int l, float sx, float sy, float p) {
	SPRITE_CHECK_VALID_VOID;
	vcSprites[i]->drawex(f, x, y, a, static_cast<SDL_RendererFlip>(l), sx, sy, p);
}

void drawSpriteMod(int i, float f, float x, float y, float c) {
	SPRITE_CHECK_VALID_VOID;
	vcSprites[i]->drawmod(f, x, y, c);
}

void drawSpriteExMod(int i, float f, float x, float y, float a, int l, float sx, float sy, float p, float c) {
	SPRITE_CHECK_VALID_VOID;
	vcSprites[i]->drawexmod(f, x, y, a, static_cast<SDL_RendererFlip>(l), sx, sy, p, c);
}

void deleteSprite(int i) {
	SPRITE_CHECK_VALID_VOID;
	delete vcSprites[i];
}

int spriteW(int i) {
	SPRITE_CHECK_VALID_INT;
	return vcSprites[i]->getw();
}

int spriteH(int i) {
	SPRITE_CHECK_VALID_INT;
	return vcSprites[i]->geth();
}

void replaceSprite(int s, const std::string& f, int w, int h, int m, int p, int x, int y) {
	if (s <= 0 || s >= vcSprites.size()) return;

	if (vcSprites[s] != 0) {
		vcSprites[s]->replaceSprite(f, w, h, m, p, x, y);
	}
	else {
		vcSprites[s] = new xySprite(f, w, h, m, p, x, y);
	}
}

void spriteSetBlendMode(int sprite, int blend) {
	if (sprite < 0 || sprite > vcSprites.size() - 1) {
		throw std::runtime_error("Invalid sprite ID. Cannot set blend mode");
	}

	SDL_BlendMode mode;
	switch (blend) {
		case 0:
			mode = SDL_BLENDMODE_NONE;
			break;
		case 1:
			mode = SDL_BLENDMODE_BLEND;
			break;
		case 2:
			mode = SDL_BLENDMODE_ADD;
			break;
		case 3:
			mode = SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ONE, SDL_BLENDFACTOR_ONE, SDL_BLENDOPERATION_SUBTRACT, SDL_BLENDFACTOR_ONE, SDL_BLENDFACTOR_ONE, SDL_BLENDOPERATION_SUBTRACT);
			break;
		case 4:
			mode = SDL_BLENDMODE_MOD;
			break;
		default:
			mode = SDL_BLENDMODE_NONE;
			break;
	};

	SDL_SetTextureBlendMode(vcTextures[vcSprites[sprite]->gettex()], mode);
}

} // namespace BruxAPI
