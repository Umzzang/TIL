# PJT 10



## API 받기

```vue
// App.vue

export default {
  
  created() {
    const URL = 'https://api.themoviedb.org/3/movie/popular'
    const API_KEY = ''
    axios({
        method: 'get',
        url: URL,
        params: {
          api_key : API_KEY,
          language: 'ko',
          region: 'KR'
        }
    }).then(res => {
        console.log(typeof(res.data.results))
        res.data.results.forEach(element => {
          this.$store.dispatch('newMovies', element)
        });
    })
  }
}

```

```
created 될때 axios 요청 보내서 받아와서 vuex state에 저장하는 식
=> 처음에 HomeView에서 작성했더니 created 할때마다 키 오류
=> App.vue로 하면 문제 없이 됨.
```





## RandomView

> 버튼 누르기 전에는 받아온 정보가 없음
>
> => 버튼을 누르면 그 때 보여 주는걸로 => v-show or v-if 사용

```vue
template>
  <div>
    <button class="btn btn-primary m-5" @click="showMovie">Pick</button>
    <br>
    <div class="row justify-content-around">
      <div v-if="show" class="card" style="width: 18rem;">
        <img :src="url+movie.poster_path" class="card-img-top mt-3">
        <div class="card-body">
        <h3 class="card-title text-success">{{ movie.title }}</h3>
        <p class="card-text">{{ movie.overview.substr(0, 80) }}...</p>
      </div>
      </div>
    </div>
  </div>
</template>

<script>
import _ from 'lodash'

export default {
  name:'RandomView',
  data() {
    return {
      movie: {},
      url : 'https://image.tmdb.org/t/p/w500',
      show: false
    }
  },

  methods: {
    showMovie() {
      const n = _.random(this.$store.state.movies.length - 1)
      this.movie = this.$store.state.movies[n]
      this.show = true
    }
  }
}
```

```
substr => overview 가 너무 길어서 80자까지 자르는 str 메서드 사용
=> v-show 를 사용하면 먼저 렌더링이 되기 때문에 초기 str이 없어서 substr 로 인해서 오류 발생
=> v-if 사용해서 참일때만 태그들 생성
```

