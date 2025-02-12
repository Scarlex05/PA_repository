#include "SceneMenu.h"

/*void SceneMenu::AddGameObject(Solid* gameObjectToAdd)
{
	this->gameObjects.push_back(gameObjectToAdd);
}*/

bool SceneMenu::IsClickInsideButton(int x, int y) {
    // Obtener las coordenadas del bot�n
    float buttonX = button.GetPosition().GetX();
    float buttonY = button.GetPosition().GetY();
    float buttonWidth = button.GetWidth();
    float buttonHeight = button.GetHeight();

    // Verificar si el clic est� dentro de los l�mites del cubo
    return (x >= buttonX - buttonWidth / 2 && x <= buttonX + buttonWidth / 2 &&
        y >= buttonY - buttonHeight / 2 && y <= buttonY + buttonHeight / 2);
}

void SceneMenu::Render() {
    this->GetCamera().Render();
    button.Render(); // Dibuja el bot�n
}

void SceneMenu::Update()
{
	/*for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(0.1f);
	}*/

}

