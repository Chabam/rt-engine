#include "object/mesh.h"
#include "object/triangle.h"
#include "object/vertice.h"

class Quad : public Mesh
{
  public:
    Quad(const Vertice &p1, const Vertice &p2, const Vertice &p3, const Vertice &p4);
    Quad(const Quad &other);
    Quad &operator=(const Quad &other);

	Vertice m_p1;
	Vertice m_p2;
	Vertice m_p3;
	Vertice m_p4;
};