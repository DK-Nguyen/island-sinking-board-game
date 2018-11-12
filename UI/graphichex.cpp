#include <graphichex.h>
#include <QPointF>
#include <QPolygonF>
#include <QVector>
#include <QBrush>
#include <QColor>

GraphicHex::~GraphicHex()
{
    return;
}

GraphicHex::GraphicHex(std::shared_ptr<Common::Hex> hex_ptr, QVector<QPointF> vertex, int id, QGraphicsItem* parent): QGraphicsPolygonItem (parent)
{
    this->vertex = vertex;
    this->hex_ptr = hex_ptr;
    this->id = id;

    // create a polygon with vertex
    QPolygonF hexagon(vertex);

    // draw the poly
    setPolygon(hexagon);
    set_color(hex_ptr->getPieceType());
}

// perform flipping of hex tile
void GraphicHex::flip()
{
    set_color("Water");
    return;
}

void GraphicHex::set_color(std::string type)
{
    QColor color;

    if (type.compare("Peak")==0)
    {
        color = Qt::gray;
    }
    else if (type.compare("Mountain")==0)
    {
        color = Qt::lightGray;
    }
    else if (type.compare("Forest")==0)
    {
        color = Qt::green;
    }
    else if (type.compare("Beach")==0)
    {
        color = Qt::yellow;
    }
    else if (type.compare("Water")==0)
    {
        color = Qt::blue;
    }
    else
    {
        color = Qt::magenta;
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    setBrush(brush);

}

std::shared_ptr<Common::Hex> GraphicHex::get_hex()
{
    return hex_ptr;
}

void GraphicHex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked(id);
}




