#ifndef _TEXTURES_H
#define _TEXTURES_H
#include <iostream>
#include "Texture.h"
class Textures
{
public:
	Textures();
	~Textures();
	Texture* getAirTexture();
	Texture* getDirt2Texture();
	Texture* getDirtTexture();
	Texture* getFloorTexture();
	Texture* getGrassTexture();
	Texture* getGrassTopTexture();
	Texture* getHighlightedAreaTexture();
	Texture* getLaserTexture();
	Texture* getStoneTexture();
	Texture* getTrashTexture();
	Texture* getWoodTexture();
	Texture* getBackgroundTestTexture();

	Texture* getCreateWorldFirstTexture();
	Texture* getCreateWorldSecondTexture();
	Texture* getExitFirstTexture();
	Texture* getExitSecondTexture();
	Texture* getPauseFirstTexture();
	Texture* getPauseSecondTexture();
	Texture* getPlayFirstTexture();
	Texture* getPlaySecondTexture();
	Texture* getPlayTexture();
	Texture* getPlay1Texture();
	Texture* getResumeFirstTexture();
	Texture* getResumeSecondTexture();
	Texture* getSaveFirstTexture();
	Texture* getSaveSecondTexture();

	Texture* getEnemy1Texture();
	Texture* getEnemy2Texture();
	Texture* getEnemy3Texture();
	Texture* getEnemy4Texture();
	Texture* getEnemy5Texture();
	Texture* getEnemy6Texture();
	Texture* getEnemy7Texture();
	Texture* getEnemy8Texture();

	Texture* getTower1Texture();
	Texture* getTower2Texture();
	Texture* getTower3Texture();
	Texture* getTower4Texture();
	Texture* getDELETETexture();
	Texture* getUpgradeDamageTexture();
	Texture* getUpgradeRangeTexture();
	Texture* getDELETE2Texture();
	Texture* getUpgradeDamage2Texture();
	Texture* getUpgradeRange2Texture();
	Texture* getSettings();
private:
	Texture* air;
	Texture* dirt2;
	Texture* dirt;
	Texture* floor;
	Texture* grass;
	Texture* grassTop;
	Texture* highlightedArea;
	Texture* laser;
	Texture* stone;
	Texture* trash;
	Texture* wood;

	Texture* createWorldFirst;
	Texture* createWorldSecond;
	Texture* exitFirst;
	Texture* exitSecond;
	Texture* pauseFirst;
	Texture* pauseSecond;
	Texture* playFirst;
	Texture* playSecond;
	Texture* play;
	Texture* play1;
	Texture* resumeFirst;
	Texture* resumeSecond;
	Texture* saveFirst;
	Texture* saveSecond;

	Texture* enemy1;
	Texture* enemy2;
	Texture* enemy3;
	Texture* enemy4;
	Texture* enemy5;
	Texture* enemy6;
	Texture* enemy7;
	Texture* enemy8;

	Texture* tower1;
	Texture* tower2; 
	Texture* tower3;
	Texture* tower4;

	Texture* backgroundTestTexture;

	Texture* deleteTower;
	Texture* UpgradeDamage;
	Texture* UpgradeRange; 
	Texture* DELETE2;
	Texture* UpgradeDamage2;
	Texture* UpgradeRange2;
	Texture* settings;
};

#endif