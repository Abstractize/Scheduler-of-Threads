FROM node

ENV NODE_ENV development

WORKDIR /app

COPY package.json ./
COPY package-lock.json ./
RUN npm install --silent
RUN npm install react-scripts@3.4.1 -g --silent

COPY . ./

EXPOSE 3000

CMD ["npm", "run", "start"]