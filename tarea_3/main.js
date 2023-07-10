import * as THREE from 'three';

// Configuración básica de Three.js
const scene = new THREE.Scene();
// Se define el fov, aspect ratio, near y far
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.z = 1;

const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Variables uniformes
// Son variables que se pasan a la GPU utilizando el fragment shader
const uniforms = {
  // Resolución de la pantalla
  u_resolution: { value: new THREE.Vector2(window.innerWidth, window.innerHeight) },
  // Variable que contiene el tiempo en segundos
  u_time: { value: 0.0 },
  // Define la cantidad de filas a la que se divide la pantalla
  u_scale: { value: 2.0 },
  // Frencuencia de la animación
  u_frecuency: { value: 0 },
  u_color: { value: new THREE.Color(0x000000) },
  u_grid: { value: false },
};

// Material personalizado
const material = new THREE.ShaderMaterial({
  uniforms: uniforms,
  fragmentShader: `
    uniform vec2 u_resolution;
    uniform float u_time;
    uniform float u_scale;
    uniform float u_frecuency;
    uniform vec3 u_color;
    uniform bool u_grid;

    // Create a array to store the m_dist values
    float m_dist[9];

    vec2 random2(vec2 p) {
      return fract(sin(vec2(dot(p, vec2(86, 311.7)), dot(p, vec2(269.5, 283.3)))) * 3.1488831);
    }

    void main() {
      vec2 st = gl_FragCoord.xy / u_resolution.xy;
      st.x *= u_resolution.x / u_resolution.y;
      vec3 color = u_color;

      // Scale
      st *= u_scale;

      // Tile the space
      vec2 i_st = floor(st);
      vec2 f_st = fract(st);

      float m_dist = 1.0;  // minimum distance

      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          // Neighbor place in the grid
          vec2 neighbor = vec2(float(j), float(i));

          // Random position from current + neighbor place in the grid
          vec2 point = random2(i_st + neighbor);

          // Animate the point
          float animationFactor = sin(u_time + 0.2 * point.x + 3.1415 * point.y);

          // if the point is pair then...
          if (mod(point.x + point.y, 2.0) > 1.00){
            point += animationFactor * u_frecuency * -vec2(sin(u_time), sin(u_time)) - (point.y *0.01);
          }else{
            point += animationFactor * u_frecuency * vec2(cos(u_time), sin(u_time)) + (point.x *0.01);
          }

          // Vector between the pixel and the point
          vec2 diff = neighbor + point - f_st;

          // Distance to the point
          float dist = length(diff);

          // Keep the closer distance
          m_dist = min(m_dist, dist);
          
        }
      }

      // Draw the min distance (distance field)
      color += m_dist;

      // Draw cell center
      color += 1. - step(.05, m_dist);

      // Draw grid
      if (u_grid) {
        color.r += step(.98, f_st.x) + step(.98, f_st.y);
      }

      gl_FragColor = vec4(color, 1.0);
    }`,
});

// Creación de geometría (un simple plano)
// Toda esta información es pasada a la GPU
const geometry = new THREE.PlaneGeometry(3, 2);
const mesh = new THREE.Mesh(geometry, material);
scene.add(mesh);

// GUI
const gui = new dat.GUI();

const config = {
  scale: 2.0,
  frequency: 0,
  color: '#000000',
  grid: false,
};

const updateScale = () => {
  uniforms.u_scale.value = config.scale;
};

const updateFrecuency = () => {
  uniforms.u_frecuency.value = config.frequency;
};

const updateColor = () => {
  uniforms.u_color.value = new THREE.Color(config.color);
};

Boolean = () => {
  uniforms.u_grid.value = config.grid;
};

gui.add(config, 'scale', 1, 100).step(1).name('Escala celulas').onChange(updateScale);
gui.add(config, 'frequency', 0, 1).step(0.1).name('Frecuencia').onChange(updateFrecuency);
gui.addColor(config, 'color').name('Color').onChange(updateColor);
gui.add(config, 'grid').name('Mostrar grilla').onChange(Boolean);

// Actualización del uniforme del mouse
function updateMousePosition(event) {
  uniforms.u_mouse.value.x = event.clientX;
  uniforms.u_mouse.value.y = window.innerHeight - event.clientY;
}

window.addEventListener('mousemove', updateMousePosition);

// Función de animación del renderizado
function animate(timestamp) {
  requestAnimationFrame(animate);

  // Actualización del uniforme de tiempo
  uniforms.u_time.value = timestamp / 1000;

  // Renderizado de la escena
  renderer.render(scene, camera);
}

animate();

