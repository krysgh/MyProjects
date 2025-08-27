let kakashi = document.getElementById('kakashiParado');
let obito = document.getElementById('obitoParado');
let isCharging = false;
let attacked = false;


document.addEventListener('keydown', (event) => {
  if (event.key === "ArrowDown") {

    if (kakashi.src.endsWith("kakashiStatic.png")) {
      kakashi.src = "images/kakashiCharging.png";
      isCharging = true;
    } 
    
    else {
      kakashi.src = "images/kakashiStatic.png";
      isCharging = false;
    }
  }

  else if(event.key === "ArrowRight"){

    if(isCharging && !attacked){
      kakashi.src = "images/kakashiChidori.png";


      let position = parseInt(kakashi.style.paddingLeft || 0);

      let interval = setInterval(() =>{

        if(position <80){
          position += 0.5;
          kakashi.style.left = position + '%';
        } else{
          clearInterval(interval);
          kakashi.src = "images/kakashiCharging.png";
          isCharging = false;
          obito.src = "images/obitoFall.png";
          obito.style.height = 140 + 'px';
          obito.style.width = 300 + 'px';
          obito.style.top = 500 + 'px';
          obito.style.paddingLeft = 75+'%';
          attacked = true;
        }
      } , 1);
    }; 

}

});