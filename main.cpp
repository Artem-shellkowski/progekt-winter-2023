#include  <SFML/Graphics.hpp>
using namespace sf;

bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
 return bat.getPosition().x <= point.x &&
  point.x <= bat.getPosition().x + 150 &&
  bat.getPosition().y <= point.y &&
  point.y <= bat.getPosition().y + 20;
}

int main()
{

    RenderWindow window(VideoMode(800, 600), "SFML");    window.setFramerateLimit(60);
    window.setFramerateLimit(60);

    CircleShape ball(15);
    ball.setFillColor({ 250, 208, 0 });
    ball.setPosition((800 - 2 * 15) / 2,
        (600 - 2 * 15) / 2);

    float ballSpeedX = 2.f;
    float ballSpeedY = 3.f;

    RectangleShape bat;
    // ��������� �������
    bat.setSize({ 150.f, 20.f });

    // ��������� �������
    bat.setPosition(325, 540);

    float batSpeedX = 2.f;
    float batSpeedY = 2.f;

    //����
//�����
    Font font;
   font.loadFromFile("Samson.ttf");
    //���������� ��� �����
    int Score = 0;
    //������ ��� ����������� �� ������
    //����� ��� ������ �����
    Text Text1;
    Text1.setString(std::to_string(Score));
    Text1.setFont(font);
    Text1.setCharacterSize(30);
    Text1.setPosition((800 - 2 * 30) / 2,
      (600 - 2 * 30) / 2);;
   

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            bat.move(-batSpeedX, 0.f);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            bat.move(batSpeedX, 0.f);
        }

        ball.move(ballSpeedX, ballSpeedY);
        if (ball.getPosition().x <= 0)
        {
            ballSpeedX = -ballSpeedX;

        }
        //��� ����������� �� ������ ������� ������
        if (ball.getPosition().x + 2 * 15 >= 800)
        {
            ballSpeedX = -ballSpeedX;
        }
        if (ball.getPosition().y + 2 * 15 >= 600)
        {
            ball.setPosition((800 - 2 * 15) / 2,
                (600 - 2 * 15) / 2);
            Score++;

        } 

        if (ball.getPosition().y <= 0)
        {
            ballSpeedY = -ballSpeedY;
        }

            //�� ����  ����� �� ����� ���� ������
            if (bat.getPosition().x < 0) {
                bat.setPosition(0.f, 540.f);
            }
            //�� ���� ����� �� ������ ���� ������
            if (bat.getPosition().x > 800 - 150) {
                bat.setPosition(650.f, 540.f);
            }

            // ����������� ����������� �������

            Vector2f leftTop{ ball.getPosition().x, ball.getPosition().y };
            Vector2f midLeft{ ball.getPosition().x, ball.getPosition().y + 15 };
            Vector2f leftBottom{ ball.getPosition().x, ball.getPosition().y +
             2 * 15 };
            Vector2f midTop{ ball.getPosition().x + 15,  ball.getPosition().y };
            Vector2f midBottom{ ball.getPosition().x + 15,  ball.getPosition().y +
             2 * 15 };
            Vector2f rightTop{ ball.getPosition().x + 2 * 15,
             ball.getPosition().y };
            Vector2f midRight{ ball.getPosition().x + 2 * 15,
             ball.getPosition().y + 15 };
            Vector2f rightBottom{ ball.getPosition().x + 2 * 15,
             ball.getPosition().y + 2 * 15 };

            //������� ���� ����� �������
            if (pointInRect(bat, midBottom) && pointInRect(bat, leftBottom) ||
                pointInRect(bat, midBottom) && pointInRect(bat, rightBottom)) {
                float ballSpeedX = -ballSpeedY;
            }
            //������ ���� ����� �������
            if (pointInRect(bat, midTop) && pointInRect(bat, leftTop) ||
                pointInRect(bat, midTop) && pointInRect(bat, rightTop)) {
                ballSpeedY = -ballSpeedY;
            }
            //������ ����� ������ ����
            //������ ����� ������� ���� 
            if (pointInRect(bat, leftTop) || pointInRect(bat, leftBottom)) {
                ballSpeedY = -ballSpeedY;
            }

            // ������ �������
            window.clear();
            window.draw(bat);
            window.draw(ball);
            window.draw(Text1);
            window.display();
        }
        return 0;
    }
