#ifndef HEXBOARD_H
#define HEXBOARD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <hex.hh>
#include <graphichex.h>
#include <graphicpawn.h>
#include <graphicactor.h>
#include <gameengine.hh>
#include <QVector>
#include <QPointF>
#include <gameboard.hh>
#include <gamestate.hh>
#include <player.hh>

class HexBoard: public QGraphicsView{
    Q_OBJECT
public:
    // constructors
    HexBoard(std::shared_ptr<Common::IGameRunner> game_engine_ptr,
             std::shared_ptr<GameBoard> gameboard_ptr,
             std::shared_ptr<GameState> gamestate_ptr,
             std::vector<std::shared_ptr<Common::IPlayer>> game_players,
             int width,
             int height,
             int board_scale,
             QWidget* parent=nullptr);

    // add hex to scene
    void add_hex(std::shared_ptr<Common::Hex> hex_ptr, int id);

    // populate main window based on data from game_board
    void populate();

    // convert cube coordinate to 2D coordinate
    std::pair<long,long> cube_to_plane(Common::CubeCoordinate coord);

    // convert cube coordinate to hex vertices coordinate
    QVector<QPointF> cube_to_vertex(Common::CubeCoordinate coord);

    // convert 2D coordinate to cube coordinate
    Common::CubeCoordinate plane_to_cube(int x_pos, int y_pos);


    // container to hold items
    QGraphicsScene* scene;

    std::shared_ptr<Common::IGameRunner> game_engine_ptr;
    std::shared_ptr<GameBoard> gameboard_ptr;
    std::shared_ptr<GameState> gamestate_ptr;
    std::vector<std::shared_ptr<Common::IPlayer>> game_players;
    int board_scale, width, height;


public slots:
    void hex_clicked(int id); // receive click signal from hex object and perform hex flipping if valid

private slots:
    void scalingTime(qreal x);
    void animFinished();


private:
    QScrollBar *h_scrollbar, *v_scrollbar;

    void wheelEvent(QWheelEvent * event);
    int wheel_schedule=10;

    QHash<int, GraphicHex*> graphic_hex_list;

};



#endif // HEXBOARD_H
