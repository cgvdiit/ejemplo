(function ($) {
  $(document).ready(function() {
    $('.promedios .grafico').each(function() {
      $(this).highcharts({
        chart: {
          type: 'gauge',
          plotBackgroundColor: null,
          plotBackgroundImage: null,
          plotBorderWidth: 0,
          plotShadow: false,
          margin: [10, 0, 0, 0]
        },
        credits: {
          enabled: false
        },
        title: {
          text: '',
          style: {
            fontSize: '10px'
          }
        },
        plotOptions: {
          series: {
            dataLabels: {
              enabled: true,
              formatter: function () {
                return Highcharts.numberFormat(Math.abs(this.point.y), 2);
              }
            }
        },
        },
        pane: {
            startAngle: -150,
            endAngle: 150,
            background: [{
                backgroundColor: {
                    linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                    stops: [
                        [0, '#FFF'],
                        [1, '#333']
                    ]
                },
                borderWidth: 0,
                outerRadius: '109%'
            }, {
                backgroundColor: {
                    linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                    stops: [
                        [0, '#333'],
                        [1, '#FFF']
                    ]
                },
                borderWidth: 1,
                outerRadius: '107%'
            }, {
            }, {
                backgroundColor: '#DDD',
                borderWidth: 0,
                outerRadius: '105%',
                innerRadius: '103%'
            }]
        },
        yAxis: {
            min: 0,
            max: 7,
            minorTickInterval: 'auto',
            minorTickWidth: 1,
            minorTickLength: 10,
            minorTickPosition: 'inside',
            minorTickColor: '#666',
            tickPixelInterval: 30,
            tickWidth: 2,
            tickPosition: 'inside',
            tickLength: 10,
            tickColor: '#666',
            labels: {
                step: 2,
                rotation: 'auto'
            },
            title: {
                text: 'Nota Promedio',
                style: {
                  width: '40px'
                },
                y: 7
            },
            plotBands: [{
                from: 6,
                to: 7,
                color: '#55BF3B' // green
            }, {
                from: 4,
                to: 6,
                color: '#DDDF0D' // yellow
            }, {
                from: 0,
                to: 4,
                color: '#DF5353' // red
            }]
        },
        series: []
      },
      );
    });
  });

}(jQuery));
