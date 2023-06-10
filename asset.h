#include <SFMLGraphics.hpp>

class SistemaParticulas : public sf :: Drawable , public sf :: Transformable
{
public:

 SistemaParticulas(unsigned int cantidad) : mParticulas(cantidad), mVertices(sf::Points, cantidad),
  mTiempoDeVida(sf::seconds(3)), mEmision(0, 0)
 {

 }

 void setEmision( sf :: Vector2f posicion )
 {
  mEmision = posicion;
 }

 void update(sf::Time tiempoTranscurrido)
 {
  for (std::size_t i = 0; i < mParticulas.size(); ++i)
  {
   //Actualiza el ciclo de vida de las particulas
   Particula &p = mParticulas[i];
   p.tiempoDeVida -= tiempoTranscurrido;

   //Si la particula esta muerta remplazala
   if (p.tiempoDeVida <= sf::Time::Zero)
   {
    resetParticula( i );
   }

   //Actualiza la posicion del del vertex correspondiente
   mVertices[i].position += p.velocidad * tiempoTranscurrido.asSeconds();

   //Actualiza el alpha o transparencia de la particula mientras esta viva
   float rango = p.tiempoDeVida.asSeconds() / mTiempoDeVida.asSeconds();
   mVertices[i].color.a = <static_cast>sf::uint8(rango * 255);
  }
 }

private:

 virtual void draw( sf :: RenderTarget &target , sf :: RenderStates states ) const
 {
  //se transforma
  states.transform = getTransform();

  //las particulas no usan textura
  states.texture = nullptr;

  //Dibuja el vertex array
  target.draw( mVertices , states );
 }

private:

 struct  Particula
 {
  sf::Vector2f velocidad;
  sf::Time tiempoDeVida;
 };

 void resetParticula(std::size_t index)
 {
  //Se le da una velocidad aleatoria y el ciclo de vida de la particula
  float angulo = (std::rand() % 360) * 3.14f / 180.f;
  float velocidad = (std::rand() % 50) + 50.f;
  mParticulas[index].velocidad = sf::Vector2f(std::cos(angulo) * velocidad, std::sin(angulo) * velocidad);
  mParticulas[index].tiempoDeVida = sf::milliseconds((std::rand() % 2000) + 1000);

  //Resetea la posicion del correspondiente vertex
  mVertices[index].position = mEmision;
 }


private:

 std::vector<Particula>mParticulas;
 sf::VertexArray mVertices;
 sf::Time mTiempoDeVida;
 sf::Vector2f mEmision;
};
