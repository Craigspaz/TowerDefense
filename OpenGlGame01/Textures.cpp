#include "Textures.h"


Textures::Textures()
{
	air = new Texture("res/air.png");
	dirt = new Texture("res/dirt.png");
	dirt2 = new Texture("res/Dirt (2).png");
	floor = new Texture("res/floor.png");
	grass = new Texture("res/grass.png");
	grassTop = new Texture("res/grassTop.png");
	highlightedArea = new Texture("res/Highlighted Area.png");
	laser = new Texture("res/Laser.png");
	stone = new Texture("res/stone.png");
	trash = new Texture("res/Trash.png");
	wood = new Texture("res/wood.png");
	createWorldFirst = new Texture("res/Buttons/Create_World_First.png");
	createWorldSecond = new Texture("res/Buttons/Create_World_Second.png");
	exitFirst = new Texture("res/Buttons/Exit_First.png");
	exitSecond = new Texture("res/Buttons/Exit_Second.png");
	pauseFirst = new Texture("res/Buttons/Pause.png");
	pauseSecond = new Texture("res/Buttons/Pause1.png");
	play = new Texture("res/Buttons/Play.png");
	playFirst = new Texture("res/Buttons/Play_First.png");
	playSecond = new Texture("res/Buttons/Play_Second.png");
	play1 = new Texture("res/Buttons/Play1.png");
	resumeFirst = new Texture("res/Buttons/Resume_First.png");
	resumeSecond = new Texture("res/Buttons/Resume_Second.png");
	saveFirst = new Texture("res/Buttons/Save_First.png");
	saveSecond = new Texture("res/Buttons/Save_Second.png");
	enemy1 = new Texture("res/Enemy/Enemy1.png");
	enemy2 = new Texture("res/Enemy/Enemy2.png");
	enemy3 = new Texture("res/Enemy/Enemy3.png");
	enemy4 = new Texture("res/Enemy/Enemy4.png");
	enemy5 = new Texture("res/Enemy/Enemy5.png");
	enemy6 = new Texture("res/Enemy/Enemy6.png");
	enemy7 = new Texture("res/Enemy/Enemy7.png");
	enemy8 = new Texture("res/Enemy/Enemy8.png");

	tower1 = new Texture("res/Tower/Tower1.png");
	tower2 = new Texture("res/Tower/Tower2.png");
	tower3 = new Texture("res/Tower/Tower3.png");
	tower4 = new Texture("res/Tower/Tower4.png");

	backgroundTestTexture = new Texture("res/background.png");

	deleteTower = new Texture("res/DELETE.png");
	UpgradeDamage = new Texture("res/UpgradeDamage.png");
	UpgradeRange = new Texture("res/UpgradeRange.png");
	DELETE2 = new Texture("res/DELETE2.png");
	UpgradeDamage2 = new Texture("res/UpgradeDamage2.png");
	UpgradeRange2 = new Texture("res/UpgradeRange2.png");
	settings = new Texture("res/settings.png");
}


Textures::~Textures()
{
	
}

Texture* Textures::getBackgroundTestTexture()
{
	return backgroundTestTexture;
}

Texture* Textures::getAirTexture()
{
	return air;
}
Texture* Textures::getDirt2Texture()
{
	return dirt2;
}
Texture* Textures::getDirtTexture()
{
	return dirt;
}
Texture* Textures::getFloorTexture()
{
	return floor;
}
Texture* Textures::getGrassTexture()
{
	return grass;
}
Texture* Textures::getGrassTopTexture()
{
	return grassTop;
}
Texture* Textures::getHighlightedAreaTexture()
{
	return highlightedArea;
}
Texture* Textures::getLaserTexture()
{
	return laser;
}
Texture* Textures::getStoneTexture()
{
	return stone;
}
Texture* Textures::getTrashTexture()
{
	return trash;
}
Texture* Textures::getWoodTexture()
{
	return wood;
}

Texture* Textures::getCreateWorldFirstTexture()
{
	return createWorldFirst;
}
Texture* Textures::getCreateWorldSecondTexture()
{
	return createWorldSecond;
}
Texture* Textures::getExitFirstTexture()
{
	return exitFirst;
}
Texture* Textures::getExitSecondTexture()
{
	return exitSecond;
}
Texture* Textures::getPauseFirstTexture()
{
	return pauseFirst;
}
Texture* Textures::getPauseSecondTexture()
{
	return pauseSecond;
}
Texture* Textures::getPlayFirstTexture()
{
	return playFirst;
}
Texture* Textures::getPlaySecondTexture()
{
	return playSecond;
}
Texture* Textures::getPlayTexture()
{
	return play;
}
Texture* Textures::getPlay1Texture()
{
	return play1;
}
Texture* Textures::getResumeFirstTexture()
{
	return resumeFirst;
}
Texture* Textures::getResumeSecondTexture()
{
	return resumeSecond;
}
Texture* Textures::getSaveFirstTexture()
{
	return saveFirst;
}
Texture* Textures::getSaveSecondTexture()
{
	return saveSecond;
}

Texture* Textures::getEnemy1Texture()
{
	return enemy1;
}
Texture* Textures::getEnemy2Texture()
{
	return enemy2;
}
Texture* Textures::getEnemy3Texture()
{
	return enemy3;
}
Texture* Textures::getEnemy4Texture()
{
	return enemy4;
}
Texture* Textures::getEnemy5Texture()
{
	return enemy4;
}
Texture* Textures::getEnemy6Texture()
{
	return enemy6;
}
Texture* Textures::getEnemy7Texture()
{
	return enemy7;
}
Texture* Textures::getEnemy8Texture()
{
	return enemy8;
}

Texture* Textures::getTower1Texture()
{
	return tower1;
}
Texture* Textures::getTower2Texture()
{
	return tower2;
}
Texture* Textures::getTower3Texture()
{
	return tower3;
}
Texture* Textures::getTower4Texture()
{
	return tower4;
}


Texture* Textures::getDELETETexture()
{
	return deleteTower;
}
Texture* Textures::getUpgradeDamageTexture()
{
	return UpgradeDamage;
}
Texture* Textures::getUpgradeRangeTexture()
{
	return UpgradeRange;
}

Texture* Textures::getDELETE2Texture()
{
	return DELETE2;
}
Texture* Textures::getUpgradeDamage2Texture()
{
	return UpgradeDamage2;
}
Texture* Textures::getUpgradeRange2Texture()
{
	return UpgradeRange2;
}

Texture* Textures::getSettings()
{
	return settings;
}
