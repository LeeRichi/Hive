NAME=inception
COMPOSE=docker-compose -f srcs/docker-compose.yml

.PHONY: all up down clean fclean re

all: up

up:
	@echo "🚀 Starting $(NAME)..."
	@$(COMPOSE) up -d --build

down:
	@echo "🛑 Stopping $(NAME)..."
	@$(COMPOSE) down

clean:
	@echo "🧹 Cleaning containers and volumes..."
	@$(COMPOSE) down --volumes --remove-orphans

fclean: clean
	@echo "🔥 Removing unused Docker data..."
	@docker system prune -af --volumes
	@docker rmi $$(docker images -f "dangling=true" -q) 2>/dev/null || true

re: fclean all
