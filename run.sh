docker-compose build
open http://localhost:3000/ | xdg-open http://localhost:3000/ | start http://localhost:3000/
docker-compose up server histogram --detach

docker-compose run --rm client