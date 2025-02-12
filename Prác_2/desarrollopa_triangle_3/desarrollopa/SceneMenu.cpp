#include "SceneMenu.h"

/*void SceneMenu::AddGameObject(Solid* gameObjectToAdd)
{
	this->gameObjects.push_back(gameObjectToAdd);
}*/

bool SceneMenu::IsClickInsideButton(int x, int y) {
    // Obtener las coordenadas del botón
    float buttonX = button.GetPosition().GetX();
    float buttonY = button.GetPosition().GetY();
    float buttonWidth = button.GetWidth();
    float buttonHeight = button.GetHeight();

    // Verificar si el clic está dentro de los límites del cubo
    return (x >= buttonX - buttonWidth / 2 && x <= buttonX + buttonWidth / 2 &&
        y >= buttonY - buttonHeight / 2 && y <= buttonY + buttonHeight / 2);
}

void SceneMenu::Render() {
    this->GetCamera().Render();
    button.Render(); // Dibuja el botón
}

void SceneMenu::Update()
{
	/*for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(0.1f);
	}*/

}

